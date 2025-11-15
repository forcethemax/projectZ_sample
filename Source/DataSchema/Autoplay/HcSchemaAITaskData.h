#pragma once

#include "Engine/DataTable.h"
#include "AI/Define/HcAIDefine.h"
#include "DataSchema/Autoplay/HcSchemaAIActionData.h"
#include "DataSchema/Autoplay/HcSchemaAIConditionData.h"
#include "HcSchemaAITaskData.generated.h"

USTRUCT(BlueprintType)
struct FHcSchemaAITaskData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	TArray<FHcSchemaAIConditionData> ReserveConditions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	TArray<FHcSchemaAIConditionData> ActionConditions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	TArray<FHcSchemaAIConditionData> ClearConditions;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	FHcSchemaAIActionData Action;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	FString Annotation;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	EHcAIContentsType ContentsType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	int ReserveCount;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Task Data")
	bool IsHighPriority;
};