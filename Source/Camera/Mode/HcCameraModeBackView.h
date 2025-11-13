#pragma once

#include "Camera/Mode/HcCameraModeControlBase.h"

class FHcCameraModeBackView final : public FHcCameraModeControlBase
{
	using Super = FHcCameraModeControlBase;

	// 생성자, 소멸자
public:
	FHcCameraModeBackView();
	FHcCameraModeBackView(EHcCameraMode In_mode) : FHcCameraModeControlBase(In_mode){}
	virtual ~FHcCameraModeBackView() = default;

public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update(float In_deltaTime) override;
};