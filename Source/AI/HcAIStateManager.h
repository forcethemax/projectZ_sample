#pragma once

#include "Classes/HcStateManager.h"

#include "AI/State/HcAIBaseState.h"

enum class EHcAIActionType : uint8;

class FHcAIManager;

class FHcAIStateAllocator : THcSharedObjectMapAllocator<EHcAIActionType, FHcAIBaseState>
{
public:
	FHcAIStateAllocator(){}
	virtual ~FHcAIStateAllocator(){}
	virtual FHcAIBaseState* Alloc(EHcAIActionType In_type) override;
};

// ai 상태 매니저

class FHcAIStateManager : public THcStateManager<FHcAIBaseState, FHcAIStateAllocator>,
	public TSharedFromThis<FHcAIStateManager>
{
	using Super = THcStateManager<FHcAIBaseState, FHcAIStateAllocator>;
	
public:
	void Initialize(TSharedPtr<FHcAIManager> In_aiManager);
};