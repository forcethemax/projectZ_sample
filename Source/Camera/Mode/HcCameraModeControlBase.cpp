#include "HcCameraModeControlBase.h"

#include "DataSchema/Camera/HcSchemaCameraModeData.h"

#include "Camera/Define/HcCameraGameDefine.h"

#include "Camera/Work/FOV/HcCameraFOVGame.h"
#include "Camera/Work/Offset/HcCameraOffsetGame.h"
#include "Camera/Work/Zoom/HcCameraZoomGame.h"
#include "Camera/Work/Location/HcCameraLocationGame.h"

void FHcCameraModeControlBase::InitSameMapSpawn(const FHcSchemaCameraModeData* In_schemaModeData)
{
	if (nullptr == In_schemaModeData)
	{
		return;
	}

	
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
}
// 모드 줌 시작
void FHcCameraModeControlBase::StartModeZoom(EHcCameraChangeZoomType In_type)
{
	
}