#pragma once

#include "Camera/Mode/HcCameraModeBase.h"

class FHcCameraModeDialog : public FHcCameraModeBase
{
	using Super = FHcCameraModeBase;
	
private:
	bool _isDirtyNextTickViewSet = false;
	
public:
	FHcCameraModeDialog();
	virtual ~FHcCameraModeDialog() = default;
public:
	virtual void Initialize() override;
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update(float In_deltaTime) override;
};
