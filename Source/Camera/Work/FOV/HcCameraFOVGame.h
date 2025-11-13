#pragma once

#include "Camera/Interface/HcCameraWork.h"
// 인게임 fov 처리
class FHcCameraFOVGame : public IHcCameraWork
{
public:
	virtual void Initialize() override{}
	virtual void Finalize() override{}
};