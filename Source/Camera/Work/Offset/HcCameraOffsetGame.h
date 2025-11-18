#pragma once

#include "Camera/Interface/HcCameraWork.h"

class FHcCameraOffsetGame : public IHcCameraWork
{
public:
	virtual void Initialize() override{}
	virtual void Finalize() override{}
	virtual void Update(float In_deltaTime)override{}
};