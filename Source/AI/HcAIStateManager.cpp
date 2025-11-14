#include "HcAIStateManager.h"

#include "AI/State/HcAIStateIdle.h"
#include "AI/State/HcAIStateAttackAnyone.h"

#include "AI/Define/HcAIDefine.h"

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

void FHcAIStateManager::Initialize(TSharedPtr<FHcAIManager> In_aiManager)
{
	TArray<EHcAIActionType> arrMode;
	
	arrMode.Add(EHcAIActionType::WAIT);
	arrMode.Add(EHcAIActionType::ATTACK_ANYONE);
	
	for (auto& iter: arrMode)
	{
		auto makeObj = MakeInstance(iter);
		makeObj->SetManager(In_aiManager, AsShared());
	}
}
