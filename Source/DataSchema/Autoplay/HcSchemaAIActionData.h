#pragma once

#include "Engine/DataTable.h"
#include "AI/Define/HcAIDefine.h"
#include "HcSchemaAIActionData.generated.h"

USTRUCT(BlueprintType)
struct FHcSchemaAIActionData : public FTableRowBase 
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Action")
	EHcAIActionType ActionType;
};
