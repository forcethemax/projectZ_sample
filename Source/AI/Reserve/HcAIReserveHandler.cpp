#include "HcAIReserveHandler.h"

#include "GeometryTypes.h"
#include "AI/Data/HcAIReserveJob.h"
#include "AI/Data/HcAITaskInfo.h"
#include "AI/Define/HcAIDefine.h"

#include "Management/ScopeGlobal/HcDataContainManager.h"

#include "Data/HcGlobalConstant.h"

void FHcAIReserveHandler::ClearAllJob()
{
	if (_arrayReserveJob.Num() != 0)
	{
		for (const auto& iter : _arrayReserveJob)
		{
			if (iter.IsValid() == false)
			{
				continue;
			}
			
			iter->ClearData();
		}
		
		_arrayReserveJob.Empty();
	}
}
void FHcAIReserveHandler::ClearRetry()
{
	_remainRetryCount = GData()->GetGlobalData()->_aiTaskRetryCount;
	_isRetry = false;
	
	_blockTargetGameId = 0;
	_isDirtyReserveRetry = false;
}
TWeakPtr<FHcAIReserveJob> FHcAIReserveHandler::GetFirstJob()
{
	if (_arrayReserveJob.Num() == 0)
	{
		return nullptr;
	}
	return _arrayReserveJob[0];
}
bool FHcAIReserveHandler::IsFirstJobAction(EHcAIActionType In_action)
{
	TWeakPtr<FHcAIReserveJob> firstJob = GetFirstJob();
	TSharedPtr<FHcAIReserveJob> sharedJob = firstJob.Pin();
	if (sharedJob.IsValid() == false)
	{
		return false;
	}
	return sharedJob->_actionType == In_action;
}

bool FHcAIReserveHandler::IsReserveJobEmpty()
{
	return (_arrayReserveJob.Num() == 0)? true: false;
}

TWeakPtr<FHcAIReserveJob> FHcAIReserveHandler::GetClearConditionCheckedFirstJob()
{
	TWeakPtr<FHcAIReserveJob> firstJob = nullptr;
	while (1)
	{
		
		if (true == CheckFirstJob(firstJob))
		{
			break;
		}
	}
	
	return firstJob;
}

bool FHcAIReserveHandler::CheckFirstJob(TWeakPtr<FHcAIReserveJob>& Out_firstJob)
{
	TWeakPtr<FHcAIReserveJob> firstJob = GetFirstJob();
	TSharedPtr<FHcAIReserveJob> sharedFirstJob = firstJob.Pin();
	if (sharedFirstJob.IsValid() == false)
	{
		return true;
	}
	bool isPass = false;
	for (auto& iter : sharedFirstJob->_clearConditions)
	{
		TSharedPtr<FHcAICondition> sharedCondition = iter.Pin();
		if (sharedCondition.IsValid() == false ||
			sharedCondition->_func == nullptr ||
			sharedCondition->_func() == false)
		{
			isPass = false;
			break;
		}
		else
		{
			isPass = true;
		}
	}
	
	if (isPass == true)
	{
		ClearReserveJob(firstJob);
		return false;
	}
	
	Out_firstJob = sharedFirstJob;
	return true;
}

void FHcAIReserveHandler::ClearReserveJob(TWeakPtr<FHcAIReserveJob> In_removeJob)
{
	TSharedPtr<FHcAIReserveJob> sharedRemoveJob = In_removeJob.Pin();
	if (sharedRemoveJob.IsValid() == false)
	{
		return;
	}
	
	sharedRemoveJob->ClearData();
	
	FHcAIReserveJob* rawRemoveJob = sharedRemoveJob.Get();
	_arrayReserveJob.RemoveAll([rawRemoveJob](const TSharedPtr<FHcAIReserveJob>& element)
	{
		return element.Get() == rawRemoveJob;
	});
}