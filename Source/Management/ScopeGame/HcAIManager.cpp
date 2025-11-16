#include "HcAIManager.h"

#include "DataSchema/Autoplay/HcSchemaAITaskData.h"

#include "AI/Data/HcAITaskInfo.h"

#include "AI/HcAIStateManager.h"

// 초기화(처음 한번만)
void FHcAIManager::Initialize()
{
	_stateManager = MakeShareable(new FHcAIStateManager());
	_stateManager->Initialize();
	
	LoadAIData();
}
// 해제
void FHcAIManager::Finalize()
{
	if (_mapTaskResolver.IsEmpty() == false)
	{
		for (auto iter: _mapTaskResolver)
		{
			if (iter.Value != nullptr)
			{
				iter.Value->Finalize();
				iter.Value = nullptr;
			}
		}
		_mapTaskResolver.Empty();
	}
	
	if (_stateManager.IsValid() == true)
	{
		_stateManager = nullptr;
	}
}

// ai 데이터 로드
void FHcAIManager::LoadAIData()
{
	UDataTable* aiTaskDataTable = LoadObject<UDataTable>(
		nullptr,
		TEXT("/Game/DataCenter/Table/Autoplay/DTHc_AITaskData.DTHc_AITaskData"));
	
	if (!aiTaskDataTable)
	{
		return;
	}
	
	const UScriptStruct* StructType = aiTaskDataTable->GetRowStruct();
	
	if (StructType == FHcSchemaAITaskData::StaticStruct())
	{
		for (auto& Pair: aiTaskDataTable->GetRowMap())
		{
			uint8* RowData = Pair.Value;
		
			FHcSchemaAITaskData* taskData = reinterpret_cast<FHcSchemaAITaskData*>(RowData);
		
			if (taskData)
			{
				TSharedPtr<FHcAITask> task = MakeShareable(new FHcAITask());
				
				for (auto conditionIter : taskData->ReserveConditions)
				{
					TSharedPtr<FHcAICondition> condition = MakeShareable(new FHcAICondition());
					condition->_conditionType = conditionIter.ConditionType;
					condition->_boolVal = conditionIter.FunctionCompareData;
					
					task->_reserveConditions.Add(condition);
				}
				
				for (auto conditionIter : taskData->ActionConditions)
				{
					TSharedPtr<FHcAICondition> condition = MakeShareable(new FHcAICondition());
					condition->_conditionType = conditionIter.ConditionType;
					condition->_boolVal = conditionIter.FunctionCompareData;
					
					task->_actionConditions.Add(condition);
				}
				
				for (auto conditionIter : taskData->ClearConditions)
				{
					TSharedPtr<FHcAICondition> condition = MakeShareable(new FHcAICondition());
					condition->_conditionType = conditionIter.ConditionType;
					condition->_boolVal = conditionIter.FunctionCompareData;
					
					task->_clearConditions.Add(condition);
				}
				
				TSharedPtr<FHcAIAction> action = MakeShareable(new FHcAIAction());
				action->_actionType = taskData->Action.ActionType;
				
				task->_action = action;
				
				task->_annotation = taskData->Annotation;
				task->_reserveCount = taskData->ReserveCount;
				
				task->_isHighPriority = taskData->IsHighPriority;
				
				TSharedPtr<FHcAITaskResolver>* findData = 
					_mapTaskResolver.Find(taskData->ContentsType);
				
				// 기존에 없으면
				if (findData==nullptr)
				{
					TSharedPtr<FHcAITaskResolver> newData = MakeShareable(new FHcAITaskResolver());
					newData->_tasks.Add(task);
					_mapTaskResolver.Add(taskData->ContentsType, newData);
				}
				// 기존에 있다면
				else
				{
					(*findData)->_tasks.Add(task);
				}
			}
		}
	}
	
	
}