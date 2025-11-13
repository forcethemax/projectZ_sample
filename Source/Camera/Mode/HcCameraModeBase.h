#pragma once

#include "Classes/HcState.h"

enum class EHcCameraMode: uint8;
enum class EHcCameraWorkType: uint8;

class IHcCameraWork;
class AplayDemoZNCharacter;

class FHcCameraRotationBase;
class FHcCameraModeHandler;

struct FHcSchemaCameraModeData;

class FHcCameraModeBase : public THcState<EHcCameraMode>,
	public TSharedFromThis<FHcCameraModeBase>
{
protected:
	// 카메라 기능들
	TMap<EHcCameraWorkType, TSharedPtr<IHcCameraWork>> _mapCamWorks; 

	AplayDemoZNCharacter* _targetCharacter;

	TWeakPtr<FHcCameraModeHandler> _modeHandler;
	
public:
	FHcCameraModeBase();
	FHcCameraModeBase(EHcCameraMode In_mode):THcState<EHcCameraMode>(In_mode){}

	virtual ~FHcCameraModeBase() = default;


public:
	virtual void Enter() override;
	virtual void Exit() override{}
	virtual void Update(float In_deltaTime) override{}

	virtual void Close() override;

public:
	// 처음 한번만 하는 초기화
	virtual void Initialize();

	virtual void InitMode(const FHcSchemaCameraModeData* In_schemaModeData);

	virtual void InitPitchMinMax(APlayerController* In_PlayerController,
		const FHcSchemaCameraModeData* In_schemaModeData);

	virtual void InitSameMapSpawn(const FHcSchemaCameraModeData* In_schemaModeData){}

	// get, set
public:
	void SetModeTarget(AplayDemoZNCharacter* In_targetChar)
	{
		_targetCharacter = In_targetChar;
	}

	// 카메라 회전 처리 접근
	TWeakPtr<FHcCameraRotationBase> GetCameraRotationBase();
	// 카메라 기능 접근
	TWeakPtr<IHcCameraWork> GetCameraWork(EHcCameraWorkType In_type);

	void SetModeHandler(TSharedPtr<FHcCameraModeHandler> In_handler)
	{
		_modeHandler = In_handler;
	}
};