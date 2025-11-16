#include "HcAIReserveJob.h"

void FHcAIReserveJob::ClearData()
{
	_targetChar = nullptr;
	
	if (_actionConditions.Num()!=0)
	{
		_actionConditions.Empty();
	}
	if (_clearConditions.Num() != 0)
	{
		_clearConditions.Empty();
	}
}
