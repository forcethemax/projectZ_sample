#pragma once

#include "IDetailGroup.h"
#include "Engine/DataTable.h"
#include "Camera/Define/HcCameraGameDefine.h"
#include "HcSchemaCameraModeData.generated.h"

USTRUCT(BlueprintType)
struct FHcSchemaCameraModeData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	EHcCameraMode CameraMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float ArmLengthTo;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float ControllerPitch;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float FOV;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	FVector SocketOffset;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float ViewPitchMin;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float ViewPitchMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float CamArmlLengthMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float CamArmLengthMin;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	FVector CamShiftPos;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float ZoomMinDepthOfFieldFocalRegionMobile;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	float ZoomMinFOV;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	bool UseZoomMinDOF;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraModeData")
	bool UseZoomMinFOV;
};