#pragma once

#include "Classes/HcManager.h"

#include "Management/HcScopeHolder.h"
#include "Management/HcScopeGame.h"

enum class EHcCameraMode : uint8;

struct FHcSchemaCameraModeData; 

class FHcCameraModeManager :
	public IHcManager
{
	// 멤버 변수들
private:
	// 현재 모드
	EHcCameraMode _currentMode;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable*  _cameraModeTable;

public:
	virtual void Initialize() override;

	// get, set 함수
public:
	EHcCameraMode GetCurrentMode() { return _currentMode; }
	void SetCurrentMode(EHcCameraMode In_mode){_currentMode = In_mode;}

	const FHcSchemaCameraModeData* FindModeDataByMode(EHcCameraMode In_mode);
};

#define HcCameraMode() UHcScopeHolder::GetGameManagerFType<FHcCameraModeManager>(UHcScopeGame::EManagerType::CameraMode)