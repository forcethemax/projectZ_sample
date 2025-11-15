#pragma once

// condition 정보

enum class EHcAIConditionType : uint8;
enum class EHcAIActionType : uint8;

class FHcAICondition
{
public:
	EHcAIConditionType _conditionType;
	TFunction<bool()> _func;
	bool _boolVal;
};
// action 정보
class FHcAIAction
{
public:
	EHcAIActionType _actionType;
};
// 조건과 행동 세트
class FHcAITask
{
public:
	TArray<TSharedPtr<FHcAICondition>> _reserveConditions;
	TArray<TSharedPtr<FHcAICondition>> _actionConditions;
	TArray<TSharedPtr<FHcAICondition>> _clearConditions;
	TSharedPtr<FHcAIAction> _action;
	// 구별id
	int id;
	
	FString _annotation;
	
	int _reserveCount;
	
	bool _isHighPriority;
public:
	virtual ~FHcAITask()= default;
	
public:
	void Finalize();
};

// ai 데이터
class FHcAITaskResolver
{
public:
	TArray<TSharedPtr<FHcAITask>> _tasks;
	
public:
	virtual ~FHcAITaskResolver()= default;
	
public:
	void Finalize();
};