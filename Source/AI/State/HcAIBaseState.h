#pragma once

#include "Classes/HcState.h"

enum class EHcAIActionType : uint8;

class FHcAIStateManager;
class FHcAIManager;

class FHcAIBaseState: public THcState<EHcAIActionType>
{
protected:
	TWeakPtr<FHcAIStateManager> _aiStateManager;
public:
	FHcAIBaseState();
	explicit FHcAIBaseState(EHcAIActionType actionType) : THcState<EHcAIActionType>(actionType){}
	virtual ~FHcAIBaseState() = default;
	
public:
	virtual void Enter() override{}
	virtual void Exit() override{}
	virtual void Update(float In_deltaTime) override{}
	
public:
	void SetManager(TSharedPtr<FHcAIStateManager> In_aiStateManager)
	{
		_aiStateManager = In_aiStateManager;
	}
};