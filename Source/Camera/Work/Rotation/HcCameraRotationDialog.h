#pragma once

#include "Camera/Work/Rotation/HcCameraRotaionBase.h"

class FHcCameraRotationDialog : public FHcCameraRotationBase
{
	using Super = FHcCameraRotationBase;
	
public:
	virtual void SetRotation(const FRotator& In_rot) override{}
};