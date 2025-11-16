#include "HcAIStateManager.h"

#include "AI/State/HcAIStateIdle.h"
#include "AI/State/HcAIStateAttackAnyone.h"

#include "AI/Define/HcAIDefine.h"

#include "AI/Reserve/HcAIReserveHandler.h"

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
	bool isFirstJboReturnPos = _aiReserveHandler->IsFirstJobAction(EHcAIActionType::MOVE_TO_AUTO_START_POS);
	
}