#include "HcAIReserveHandler.h"

#include "AI/Data/HcAIReserveJob.h"
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