#pragma once

#include "Camera/Interface/HcCameraWork.h"

class FHcCameraModeBase;

class FHcCameraZoomGame : public IHcCameraWork
{
protected:
	TWeakPtr<FHcCameraModeBase> _targetMode;
	
public:
	virtual void Initialize() override{}
	virtual void Finalize() override{}
	virtual void SetMode(TSharedPtr<FHcCameraModeBase> In_mode) override
	{
		_targetMode = In_mode;
	}
};