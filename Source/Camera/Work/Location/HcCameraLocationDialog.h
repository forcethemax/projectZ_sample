#pragma once

#include "Camera/Work/Location/HcCameraLocationGame.h"

class FHcCameraLocationDialog : public FHcCameraLocationGame
{
	using Super = FHcCameraLocationGame;
	
public:
	virtual void OnFinishLerp() override{}
};