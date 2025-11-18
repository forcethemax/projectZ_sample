#pragma once

class FHcCameraModeBase;
class AplayDemoZNCharacter;

class IHcCameraWork
{
public:
	virtual ~IHcCameraWork() = default;

public:
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
	virtual void Update(float In_deltaTime) = 0;
	virtual void OnFinishLerp(){}
	virtual void SetMode(TSharedPtr<FHcCameraModeBase> In_mode){}
	virtual void SetWorkTarget(AplayDemoZNCharacter* In_target){}
};