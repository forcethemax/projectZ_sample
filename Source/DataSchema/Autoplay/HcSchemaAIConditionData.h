#pragma once

#include "Engine/DataTable.h"
#include "AI/Define/HcAIDefine.h"
#include "HcSchemaAIConditionData.generated.h"

USTRUCT(BlueprintType)
struct FHcSchemaAIConditionData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Condition")
	EHcAIConditionType ConditionType;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Condition")
	bool FunctionCompareData;
};