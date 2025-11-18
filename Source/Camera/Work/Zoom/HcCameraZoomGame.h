#pragma once

#include "Camera/Interface/HcCameraWork.h"

class FHcCameraModeBase;
class AplayDemoZNCharacter;

enum class EHcCameraChangeZoomType: uint8;

class FHcCameraZoomGame : public IHcCameraWork
{
protected:
	// 타겟 모드
	TWeakPtr<FHcCameraModeBase> _targetMode;
	// 터치에 의한 줌인지
	bool _isTouchZoom = false;
	
	AplayDemoZNCharacter* _targetCharacter;
	
public:
	virtual void Initialize() override{}
	virtual void Finalize() override
	{
		_targetMode = nullptr;
	}
	virtual void Update(float In_deltaTime)override{}
	virtual void SetMode(TSharedPtr<FHcCameraModeBase> In_mode) override
	{
		_targetMode = In_mode;
	}
	virtual void SetWorkTarget(AplayDemoZNCharacter* In_target) override {_targetCharacter = In_target;} 
public:	
	// 모드 줌 시작
	void StartModeZoom(float In_armLengthTo, EHcCameraChangeZoomType In_type);
	
	
	// get, set
public:
	// 줌 세팅
	void SetZoom(float In_val);
};