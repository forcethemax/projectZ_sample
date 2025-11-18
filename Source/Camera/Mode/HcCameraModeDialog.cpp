#include "HcCameraModeDialog.h"

#include "Camera/Define/HcCameraGameDefine.h"

#include "Camera/Work/DOF/HcCameraDOFGame.h"
#include "Camera/Work/FOV/HcCameraFOVDialog.h"
#include "Camera/Work/Location/HcCameraLocationDialog.h"
#include "Camera/Work/Rotation/HcCameraRotationDialog.h"
#include "Camera/Work/Zoom/HcCameraZoomDialog.h"
#include "Camera/Work/Rotation/HcCameraRotationDialogCutLoop.h"

FHcCameraModeDialog::FHcCameraModeDialog() : FHcCameraModeBase(EHcCameraMode::Dialog)
{
	
}
void FHcCameraModeDialog::Initialize()
{
	TSharedPtr<IHcCameraWork> fovWork = MakeShareable(new FHcCameraFOVDialog());
	fovWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::FOVWork, fovWork);
	
	TSharedPtr<IHcCameraWork> rotationWork = MakeShareable(new FHcCameraRotationDialog());
	rotationWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::RotationWork, rotationWork);
	
	TSharedPtr<IHcCameraWork> locationWork = MakeShareable(new FHcCameraLocationDialog());
	locationWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::LocationWork, locationWork);
	
	TSharedPtr<IHcCameraWork> zoomWork = MakeShareable(new FHcCameraZoomDialog());
	zoomWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::ZoomWork, zoomWork);
	
	TSharedPtr<IHcCameraWork> rotationDialogCutLoopWork = MakeShareable(new FHcCameraRotationDialog());
	rotationDialogCutLoopWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::DialogCutLoopRotationWork, rotationDialogCutLoopWork);
}
void FHcCameraModeDialog::Enter()
{
	
}
void FHcCameraModeDialog::Exit()
{
	
}
void FHcCameraModeDialog::Update(float In_deltaTime)
{
	
}