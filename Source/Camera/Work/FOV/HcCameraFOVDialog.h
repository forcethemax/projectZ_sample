#pragma once

#include "Camera/Work/FOV/HcCameraFOVGame.h"

class FHcCameraFOVDialog : public FHcCameraFOVGame
{
	using Super = FHcCameraFOVGame;
	
public:
	virtual float GetRotSpeed() const{return 0.0f;}
	virtual void SetNowSpeed(float In_speed) override {}
};