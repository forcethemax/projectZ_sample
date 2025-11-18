#pragma once

#include "Engine/DataTable.h"

#include "Camera/Define/HcDialogCameraViewType.h"

#include "HcSchemaCameraDialogViewData.generated.h"

USTRUCT(BlueprintType)
struct FHcSchemaCameraDialogViewData : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraDialogViewData")
	FString desc;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraDialogViewData")
	EHcDialogCameraViewType type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="armLength"))
	float armLength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(Tooltip="바라보는 쪽에서 추가되는 오프셋(방향 변경)", DisplayName="rootOffset"))
	FVector rootOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(Tooltip="방향에 따라 이동 시키는 값", DisplayName="shiftOffset"))
	FVector shiftOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="lookTargetOffset"))
	FVector lookTargetOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="FOV"))
	float FOV;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="bOverride_DepthOfFieldFstop"))
	bool bOverride_DepthOfFieldFstop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(DisplayName="DepthOfFieldFstop", Tooltip="Defines the opening of the camera lens, Aperture is 1/fstop, typical lens go down to f/1.2 (large opening), larger numbers reduce the DOF effect"))
	float DepthOfFieldFstop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="bOverride_DepthOfFieldFocalDistance"))
	bool bOverride_DepthOfFieldFocalDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(DisplayName="DepthOfFieldFocalDistance", Tooltip="Distance in which the Depth of Field effect should be sharp, in unreal units (cm)"))
	float DepthOfFieldFocalDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="bOverride_DepthOfFieldFocalRegion"))
	bool bOverride_DepthOfFieldFocalRegion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(DisplayName="DepthOfFieldFocalRegion", Tooltip=" Artificial region where all content is in focus, starting after DepthOfFieldFocalDistance, in unreal units  (cm)"))
	float DepthOfFieldFocalRegion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="isCameraMoveable"))
	bool isCameraMoveable;
	
};