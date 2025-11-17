#pragma once

class FHcAIReserveJob;
enum class EHcAIActionType : uint8;

class FHcAIReserveHandler
{
private:
	TArray<TSharedPtr<FHcAIReserveJob>> _arrayReserveJob;
	TArray<TSharedPtr<FHcAIReserveJob>> _arrayPostAddReserveJob;
	
	int _remainRetryCount = 0;
	bool _isRetry = false;
	
	int64 _blockTargetGameId =0;
	bool _isDirtyReserveRetry = false;
public:
	void ClearAllJob();
	void ClearRetry();
public:
	TWeakPtr<FHcAIReserveJob> GetFirstJob();
	// 첫번째 잡이 해당 액션인가
	// 없으면 false
	bool IsFirstJobAction(EHcAIActionType In_action);
	
	bool IsReserveJobEmpty();
};