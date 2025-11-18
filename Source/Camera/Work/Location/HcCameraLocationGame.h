#pragma once
#include "CoreMinimal.h"

#include "Camera/Interface/HcCameraWork.h"

class FHcCameraModeBase;

class FHcCameraLocationGame : public IHcCameraWork
{
protected:
	TWeakPtr<FHcCameraModeBase> _targetMode;
	
public:
	virtual void Initialize() override{}
	virtual void Finalize() override
	{
		_targetMode = nullptr;
	}
	virtual void Update(float In_deltaTime)override{}
	virtual void SetMode(TSharedPtr<FHcCameraModeBase> In_mode) override
	{
		_targetMode = In_mode;
	}
};