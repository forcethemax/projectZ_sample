#pragma once

class FHcCameraModeBase;

class IHcCameraWork
{
public:
	virtual ~IHcCameraWork() = default;

public:
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
	
	virtual void SetMode(TSharedPtr<FHcCameraModeBase> In_mode){}
};