#pragma once

class FHcAIReserveJob;
enum class EHcAIActionType : uint8;

class FHcAIReserveHandler
{
private:
	TArray<TWeakPtr<FHcAIReserveJob>> _arrayReserveJob;
	TArray<TWeakPtr<FHcAIReserveJob>> _arrayPostAddReserveJob;
	
public:
	TWeakPtr<FHcAIReserveJob> GetFirstJob();
	// 첫번째 잡이 해당 액션인가
	// 없으면 false
	bool IsFirstJobAction(EHcAIActionType In_action);
};