#pragma once
#include "CoreMinimal.h"

#include "Camera/Interface/HcCameraWork.h"

class FHcCameraDOFGame : public IHcCameraWork
{
public:
	virtual void Initialize() override{}
	virtual void Finalize() override{}
	virtual void Update(float In_deltaTime)override{}
};