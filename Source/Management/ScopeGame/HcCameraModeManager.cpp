#include "HcCameraModeManager.h"

#include "DataSchema/Camera/HcSchemaCameraModeData.h"

#include "UObject/ConstructorHelpers.h"
#include "UObject/EnumProperty.h"

#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

void FHcCameraModeManager::Initialize()
{
	UDataTable* CameraModeTable = LoadObject<UDataTable>(
	nullptr,
	TEXT("/Game/DataCenter/Table/Camera/DTHc_CameraModeData.DTHc_CameraModeData"));

	_cameraModeTable = CameraModeTable;
}


const FHcSchemaCameraModeData* FHcCameraModeManager::FindModeDataByMode(EHcCameraMode In_mode)
{
	if (!_cameraModeTable)
		return nullptr;


	// 1. UEnum* 포인터 가져오기
	// StaticEnum<T>()는 해당 UENUM 타입에 대한 UEnum 포인터를 반환합니다.
	const UEnum* enumPtr = StaticEnum<EHcCameraMode>();

	if (enumPtr == nullptr)
	{
		return nullptr;
	}
	
	// 1. GetNameStringByValue()를 사용해 값 이름만 FString으로 가져옵니다 
	FString ValueName = enumPtr->GetNameStringByValue((int64)In_mode);

	// 2. FString을 FName으로 변환합니다.
	FName rowName = FName(*ValueName);
	
	
	return _cameraModeTable->FindRow<FHcSchemaCameraModeData>(rowName, TEXT("FindModeDataByMode"));
}