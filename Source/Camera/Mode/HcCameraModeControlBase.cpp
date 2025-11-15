#include "HcCameraModeControlBase.h"

#include "DataSchema/Camera/HcSchemaCameraModeData.h"

#include "Camera/Define/HcCameraGameDefine.h"

#include "Camera/Work/FOV/HcCameraFOVGame.h"
#include "Camera/Work/Offset/HcCameraOffsetGame.h"
#include "Camera/Work/Zoom/HcCameraZoomGame.h"
#include "Camera/Work/Location/HcCameraLocationGame.h"
#include "Camera/Work/Offset/HcCameraTargetOffsetGame.h"

#include "Management/ScopeGame/HcCameraModeManager.h"

void FHcCameraModeControlBase::InitSameMapSpawn(const FHcSchemaCameraModeData* In_schemaModeData)
{
	if (nullptr == In_schemaModeData)
	{
		return;
	}

	StartModeZoom(EHcCameraChangeZoomType::NoLerp);
}
void FHcCameraModeControlBase::Initialize()
{
	Super::Initialize();

	TSharedPtr<IHcCameraWork> fovWork = MakeShareable(new FHcCameraFOVGame());
	fovWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::FOVWork,fovWork);

	TSharedPtr<IHcCameraWork> offsetWork = MakeShareable(new FHcCameraOffsetGame());
	offsetWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::OffsetWork, offsetWork);

	TSharedPtr<IHcCameraWork> zoomWork =MakeShareable(new FHcCameraZoomGame());
	zoomWork->Initialize();
	zoomWork->SetMode(AsShared());
	_mapCamWorks.Add(EHcCameraWorkType::ZoomWork, zoomWork);

	TSharedPtr<IHcCameraWork> locationWork = MakeShareable(new FHcCameraLocationGame());
	locationWork->Initialize();
	locationWork->SetMode(AsShared());
	_mapCamWorks.Add(EHcCameraWorkType::LocationWork, locationWork);
	
	TSharedPtr<IHcCameraWork> targetOffsetWork = MakeShareable(new FHcCameraTargetOffsetGame());
	targetOffsetWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::OffsetWork, targetOffsetWork);
}
// 모드 줌 시작
void FHcCameraModeControlBase::StartModeZoom(EHcCameraChangeZoomType In_type)
{
	TWeakPtr<FHcCameraZoomGame> zoomWork = GetCameraZoomGame();
	TSharedPtr<FHcCameraZoomGame> sharedZoomWork = zoomWork.Pin();
	if (sharedZoomWork.IsValid() == false)
	{
		return;
	}
	
	float zoomVal = GetStartModeZoom();
	//sharedZoomWork->Sta
}

// 시작 모드 줌 값 얻어오기
float FHcCameraModeControlBase::GetStartModeZoom()
{
	EHcCameraMode nowMode = GetType();
	const FHcSchemaCameraModeData* camModeData =  HcCameraMode()->FindModeDataByMode(nowMode);
	
	if (camModeData == nullptr)
	{
		return 0.0f;
	}
	
	float zoomVal = camModeData->ArmLengthTo;
	return zoomVal;
}

TWeakPtr<FHcCameraZoomGame> FHcCameraModeControlBase::GetCameraZoomGame()
{
	TWeakPtr<IHcCameraWork> work = GetCameraWork(EHcCameraWorkType::ZoomWork);
	if (work == nullptr)
	{
		return nullptr;
	}
	TSharedPtr<IHcCameraWork> baseSharedPtr = work.Pin();
	if (baseSharedPtr.IsValid() == false)
	{
		return nullptr;
	}
	
	TSharedPtr<FHcCameraZoomGame> derivedSharedPtr = 
		StaticCastSharedPtr<FHcCameraZoomGame>(baseSharedPtr);
	
	if (derivedSharedPtr.IsValid() == false)
	{
		return nullptr;
	}
	
	return derivedSharedPtr;
}