#pragma once

#include "Classes/HcStateManager.h"

#include "AI/State/HcAIBaseState.h"

enum class EHcAIActionType : uint8;

class FHcAIManager;
class FHcAIReserveHandler;
class FHcAITaskResolver;
class FHcAITask;
class FHcAIReserveJob;

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
	
private:
	TSharedPtr<FHcAIReserveHandler> _aiReserveHandler;
	bool _isDirtyRemakeList = false;
	
	TWeakPtr<FHcAITaskResolver> _taskResolver;
	
	int64 _waitStartRemakeListTime = 0;
	bool _isWaitRemakeList = false;
public:
	void Initialize();
	void Finalize();
	void ProcessReserveJob();
	
	bool MakeJobsByEvaluateConditions(bool In_isHighPriority);
	
	bool MakeJobByEvaluateCondition(TWeakPtr<FHcAITask> In_info, bool In_isHighPriority);
	
	void ChangeContentsType(TSharedPtr<FHcAITaskResolver> In_aiResolver);
	
	// 상태 초기화
	void ClearState();
	
	void ChangeStateByCurrentReserveJob();
	
	
};