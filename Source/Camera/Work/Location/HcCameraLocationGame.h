#pragma once
#include "CoreMinimal.h"

#include "Camera/Interface/HcCameraWork.h"

class FHcCameraModeBase;

class FHcCameraLocationGame : public IHcCameraWork
{
protected:
	TWeakPtr<FHc>
	
public:
	virtual void Initialize() override{}
	virtual void Finalize() override{}
};