#pragma once

#include "Camera/Mode/HcCameraModeBase.h"
#include "Message/HcMessageInput.h"

class FHcCameraZoomGame;

struct FHcSchemaCameraModeData;

enum class EHcCameraChangeZoomType : uint8;

class FHcCameraModeControlBase : public FHcCameraModeBase
{
	using Super = FHcCameraModeBase;
protected:
	// 현재 터치 중인지
	bool _bTouchOn = false;
	
private:
	TArray<TPair<MessageInput, FDelegateHandle>> _arrayInputMessageDelegates;

	// 생성자, 소멸자
public:
	FHcCameraModeControlBase() = default;
	FHcCameraModeControlBase(EHcCameraMode In_mode) : FHcCameraModeBase(In_mode) {}
	virtual ~FHcCameraModeControlBase() = default;

public:
	virtual void InitSameMapSpawn(const FHcSchemaCameraModeData* In_schemaModeData) override;
	virtual void Initialize() override;

public:
	// 모드 줌 시작
	virtual void StartModeZoom(EHcCameraChangeZoomType In_type);
	// 시작 모드 줌 값 얻어오기
	virtual float GetStartModeZoom();
	
	// get, set
public:
	TWeakPtr<FHcCameraZoomGame> GetCameraZoomGame();
};