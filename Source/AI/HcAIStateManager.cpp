#include "HcAIStateManager.h"

#include "AI/State/HcAIStateIdle.h"
#include "AI/State/HcAIStateAttackAnyone.h"

#include "AI/Define/HcAIDefine.h"

#include "AI/Reserve/HcAIReserveHandler.h"
#include "Data/HcAIReserveJob.h"
#include "Data/HcAITaskInfo.h"

#include "Misc/DateTime.h"

FHcAIBaseState* FHcAIStateAllocator::Alloc(EHcAIActionType In_type)
{
	if (In_type == EHcAIActionType::WAIT)
	{
		return new FHcAIStateIdle();
	}
	else if (In_type == EHcAIActionType::ATTACK_ANYONE)
	{
		return new FHcAIStateAttackAnyone();
	}
	return nullptr;
}

void FHcAIStateManager::Initialize()
{
	TArray<EHcAIActionType> arrMode;
	
	arrMode.Add(EHcAIActionType::WAIT);
	arrMode.Add(EHcAIActionType::ATTACK_ANYONE);
	
	for (auto& iter: arrMode)
	{
		auto makeObj = MakeInstance(iter);
		makeObj->SetManager(AsShared());
	}
	
	_aiReserveHandler = MakeShareable(new FHcAIReserveHandler());
}
void FHcAIStateManager::Finalize()
{
	_aiReserveHandler = nullptr;
}
void FHcAIStateManager::ProcessReserveJob()
{
	if (_aiReserveHandler.IsValid() == false)
	{
		return;
	}
	
	EHcAIDelayType delayType = EHcAIDelayType::NONE;
	// 시작 지역으로 들아가는게 첫번째인지
	bool isFirstJobReturnPos = _aiReserveHandler->IsFirstJobAction(EHcAIActionType::MOVE_TO_AUTO_START_POS);
	// 대기가 첫번째인지
	bool isFirstJobWaitSecond = _aiReserveHandler->IsFirstJobAction(EHcAIActionType::WAIT_SECOND);
	
	// empty
	if (_aiReserveHandler->IsReserveJobEmpty() == true ||
		(_isDirtyRemakeList == true &&
			// 첫번째가 원점 돌아가는 모드면 clear를 하지 않는다
			// 타이머 때문에 돌아가는 job이 삭제되어서 돌아가지 못하고 더 전투하는 현상 때문
			// 대기 시간도 추가로 체크
			(isFirstJobReturnPos == false && isFirstJobWaitSecond == false)
			))
	{
		bool isByRemakeListTimmer = false;
		if (_isDirtyRemakeList == true)
		{
			_isDirtyRemakeList = false;
			isByRemakeListTimmer = true;
			
			_aiReserveHandler->ClearAllJob();
		}
		else
		{
			_aiReserveHandler->ClearRetry();
		}
		
		// 예약 데이터 추가됨
		MakeJobsByEvaluateConditions(false);
		
		if (isByRemakeListTimmer == true)
		{
			delayType = EHcAIDelayType::NONE;
		}
		else
		{
			delayType = EHcAIDelayType::MAKE_JOB_DELAY;
		}
		_waitStartRemakeListTime = FDateTime::UtcNow().GetTicks();
		_isWaitRemakeList = true;
	}
	else if (_aiReserveHandler->GetIsRetry() == true)
	{
		delayType = EHcAIDelayType::RETRY_DELAY;
	}
	
	if (delayType == EHcAIDelayType::NONE)
	{
		_aiReserveHandler->ClearRetry();
		ChangeStateByCurrentReserveJob();
	}
	else
	{
		// 대기 시간 처리
	}
}
void FHcAIStateManager::ChangeStateByCurrentReserveJob()
{
	if (_aiReserveHandler.IsValid() == false)
	{
		return;
	}
	
	TWeakPtr<FHcAIReserveJob> reserveJob = _aiReserveHandler->GetClearConditionCheckedFirstJob();
	TSharedPtr<FHcAIReserveJob> sharedReserveJob = reserveJob.Pin();
	if (sharedReserveJob.IsValid() == false)
	{
		return;
	}
	
	bool isPass = true;
	for (auto& actionCondition : sharedReserveJob->_actionConditions)
	{
		TSharedPtr<FHcAICondition> sharedCondition = actionCondition.Pin();
		if (sharedCondition.IsValid() == false ||
			sharedCondition->_func == nullptr ||
			sharedCondition->_func() == false)
		{
			isPass = false;
			break;
		}
	}
	
	if (isPass == true)
	{
		ChangeState(sharedReserveJob->_actionType);
	}
}
bool FHcAIStateManager::MakeJobsByEvaluateConditions(bool In_isHighPriority)
{
	TSharedPtr<FHcAITaskResolver> sharedTaskResolver =  _taskResolver.Pin();
	if (sharedTaskResolver.IsValid() == false)
	{
		return false;
	}
	
	bool isMakeJob = false;
	if (In_isHighPriority == false)
	{
		// auto on 이면서 
		// 현재 타겟이 있다면  추가 
	}
	
	for (int i=0; i < sharedTaskResolver->_tasks.Num() ; ++i)
	{
		TSharedPtr<FHcAITask> task = sharedTaskResolver->_tasks[i];
		if (task.IsValid() == false)
		{
			continue;
		}
		
		if (task->_isHighPriority != In_isHighPriority)
		{
			continue;
		}
		
		if (true == MakeJobByEvaluateCondition(task, In_isHighPriority))
		{
			isMakeJob = true;
		}
		
	}
	// post make jobs
	
	return isMakeJob;
}
bool FHcAIStateManager::MakeJobByEvaluateCondition(TWeakPtr<FHcAITask> In_info, bool In_isHighPriority)
{
	TSharedPtr<FHcAITask> sharedTask = In_info.Pin();
	if (sharedTask.IsValid() == false)
	{
		return false;
	}
	
	bool isPassed = true;
	
	for (const auto& iter : sharedTask->_reserveConditions)
	{
		if (iter.IsValid() == false || iter->_func == nullptr ||
			iter->_func() == false)
		{
			isPassed = false;
			break;
		}
		
		// 모든 조건 만족하면
		// job에 값이 있다면
		if (true == isPassed &&
			sharedTask->_action.IsValid() == true)
		{
			// make job
			return true;
		}
	}
	
	return false;
}
void FHcAIStateManager::ChangeContentsType(TSharedPtr<FHcAITaskResolver> In_aiResolver)
{
	_taskResolver = In_aiResolver;
	ClearState();
}

// 상태 초기화
void FHcAIStateManager::ClearState()
{
	// 대기로 변경
	// 처음이거나
	// 대기가 아니면 변경
	if (false == CurrentState.IsValid() ||
		CurrentState.Pin()->GetType() != EHcAIActionType::WAIT)
	{
		ChangeState(EHcAIActionType::WAIT);
	}
}