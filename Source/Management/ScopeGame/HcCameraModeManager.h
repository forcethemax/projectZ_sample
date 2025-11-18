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
	// 컷 페이드 사용하는가
	bool _isUseCutFadeOut = false;
	
	bool _isZoomFirstCameraMove = false;
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
	
	void SetIsUseCutFadeOut(bool In_isUseCutFadeOut)
	{
		// 처음엔 선택적으로 사용하다 나중엔 고정 되어버림 
		// _isUseCutFadeOut = In_isUseCutFadeOut;
		_isUseCutFadeOut = true;
	}
	
	void SetIsZoomFirstCameraMove(bool In_isZoomFirstCameraMove)
	{
		_isZoomFirstCameraMove = In_isZoomFirstCameraMove;
	}
};

#define HcCameraMode() UHcScopeHolder::GetGameManagerFType<FHcCameraModeManager>(UHcScopeGame::EManagerType::CameraMode)