#include "HcAIReserveHandler.h"

#include "AI/Data/HcAIReserveJob.h"
#include "AI/Define/HcAIDefine.h"


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