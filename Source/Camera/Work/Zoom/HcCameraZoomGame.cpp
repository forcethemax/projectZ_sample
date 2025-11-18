#include "HcCameraZoomGame.h"

#include "Camera/Define/HcCameraGameDefine.h"

#include "playDemoZNCharacter.h"

// 모드 줌 시작
void FHcCameraZoomGame::StartModeZoom(float In_armLengthTo, EHcCameraChangeZoomType In_type)
{
	_isTouchZoom = false;
	
	float zoomFrom = 0.0f;
	if (In_type == EHcCameraChangeZoomType::NoLerp)
	{
		
	}
}

// 줌 세팅
void FHcCameraZoomGame::SetZoom(float In_val)
{
	if (_targetCharacter.IsValid() == false)
	{
		return;
	}
	
	//_targetCharacter->GetS
}