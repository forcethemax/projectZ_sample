#pragma once
class ACharacter;
class FHcAICondition;
enum class EHcAIActionType : uint8;

class FHcAIReserveJob
{
public:
	TWeakObjectPtr<ACharacter> _targetChar;
	EHcAIActionType _actionType;
	TArray<TWeakPtr<FHcAICondition>> _actionConditions;
	TArray<TWeakPtr<FHcAICondition>> _clearConditions;
	
	bool _isHighPriority = false;
	
public:
	virtual ~FHcAIReserveJob() = default;
	
public:
	void ClearData();
};