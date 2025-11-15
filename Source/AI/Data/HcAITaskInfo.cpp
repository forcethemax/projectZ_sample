#include "HcAITaskInfo.h"

void FHcAITask::Finalize()
{
	if (_reserveConditions.Num() > 0)
	{
		for (auto iter: _reserveConditions)
		{
			if (iter == nullptr)
			{
				continue;
			}
			
			iter->_func = nullptr;
			iter = nullptr;
		}
		_reserveConditions.Empty();
	}
	
	if (_actionConditions.Num() > 0)
	{
		for (auto iter: _actionConditions)
		{
			if (iter == nullptr)
			{
				continue;
			}
			iter->_func = nullptr;
			iter = nullptr;
		}
		_actionConditions.Empty();
	}
	if (_clearConditions.Num() > 0)
	{
		for (auto iter: _clearConditions)
		{
			if (iter == nullptr)
			{
				continue;
			}
			iter->_func = nullptr;
			iter = nullptr;
		}
		_clearConditions.Empty();
	}
	
	_action = nullptr;
	
}

void FHcAITaskResolver::Finalize()
{
	if (_tasks.Num() > 0)
	{
		for (auto iter: _tasks)
		{
			if (iter == nullptr)
			{
				continue;
			}
			iter->Finalize();
			iter = nullptr;
		}
		_tasks.Empty();
	}
}