#pragma once

#include "Camera/Mode/HcCameraModeControlBase.h"

class FHcCameraModeQuarter final : public FHcCameraModeControlBase
{
	using Super = FHcCameraModeControlBase;
	// 생성, 소멸자
public:
	FHcCameraModeQuarter();
	virtual ~FHcCameraModeQuarter() = default;

public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update(float In_deltaTime) override;
};