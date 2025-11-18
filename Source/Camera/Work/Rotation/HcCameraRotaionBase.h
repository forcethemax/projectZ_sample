#pragma once

#include "CoreMinimal.h"

#include "Camera/Interface/HcCameraWork.h"

class FHcCameraRotationBase : public IHcCameraWork
{
public:
	virtual ~FHcCameraRotationBase() = default;

public:
	virtual void InitMode(){}
	virtual void Initialize() override{}
	virtual void Finalize() override{}
	virtual void Update(float In_deltaTime)override{}
public:
	virtual void SetRotation(const FRotator& In_rot){}
};