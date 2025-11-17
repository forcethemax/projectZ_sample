#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "HcGlobalConstant.generated.h"

UCLASS(BlueprintType, Category = "GlobalConstant")
class UHcGlobalConstant : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Input")
	FSoftObjectPath _inputBinder;
	
public:
	UPROPERTY(EditAnywhere, Category = "Auto")
	int _aiTaskRetryCount =3;
};