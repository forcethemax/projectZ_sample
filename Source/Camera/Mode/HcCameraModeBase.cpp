#include "HcCameraModeBase.h"

#include "playDemoZNCharacter.h"

#include "Camera/Define/HcCameraGameDefine.h"

#include "Camera/Work/DOF/HcCameraDOFGame.h"
#include "Camera/Work/Rotation/HcCameraRotaionBase.h"

#include "Camera/HcCameraModeHandler.h"

#include "Management/ScopeGame/HcCameraModeManager.h"

#include "DataSchema/Camera/HcSchemaCameraModeData.h"

#include "Util/HcClassUtil.h"

#include "Templates/SharedPointer.h"

FHcCameraModeBase::FHcCameraModeBase() : THcState<EHcCameraMode>(EHcCameraMode::Quarter)
{
}

// 처음 한번만 하는 초기화
void FHcCameraModeBase::Initialize()
{
	TSharedPtr<IHcCameraWork> dofWork = MakeShareable(new FHcCameraDOFGame());
	dofWork->Initialize();
	_mapCamWorks.Add(EHcCameraWorkType::DOFWork, dofWork);
}

void FHcCameraModeBase::Close()
{
	if (_mapCamWorks.Num() > 0)
	{
		for (auto& iter : _mapCamWorks)
		{
			if (iter.Value == nullptr)
			{
				continue;
			}

			iter.Value->Finalize();
		}

		_mapCamWorks.Empty();
	}
}


void FHcCameraModeBase::Enter()
{
	EHcCameraMode nowMode = GetType();
	
	const FHcSchemaCameraModeData* camData =  HcCameraMode()->FindModeDataByMode(nowMode);

	InitMode(camData);

	if (TSharedPtr<FHcCameraModeHandler> handler = _modeHandler.Pin())
	{
		EHcCameraInitModeType initModeType = handler->GetInitModeType();
		switch (initModeType)
		{
		case EHcCameraInitModeType::SameMapSpawn:
			
			break;
		}
	}
}

void FHcCameraModeBase::InitMode(const FHcSchemaCameraModeData* In_schemaModeData)
{
	if (nullptr == In_schemaModeData ||
		nullptr == _targetCharacter)
	{
		return;
	}

	if (_targetCharacter->Controller &&
		_targetCharacter->Controller->IsLocalController())
	{
		APlayerController* const PC =
			CastChecked<APlayerController>(_targetCharacter->Controller);

		InitPitchMinMax(PC, In_schemaModeData);
	}

	TWeakPtr<FHcCameraRotationBase> rotationWork = GetCameraRotationBase();
	TSharedPtr<FHcCameraRotationBase> sharedWork = rotationWork.Pin();
	if (sharedWork.IsValid() ==false)
	{
		return;
	}

	sharedWork->InitMode();
}
void FHcCameraModeBase::InitPitchMinMax(APlayerController* In_PlayerController,
		const FHcSchemaCameraModeData* In_schemaModeData)
{
	if (nullptr == In_PlayerController)
	{
		return;
	}

	if (nullptr != In_PlayerController->PlayerCameraManager)
	{
		In_PlayerController->PlayerCameraManager->ViewPitchMin =
			In_schemaModeData->ViewPitchMin;
		In_PlayerController->PlayerCameraManager->ViewPitchMax =
			In_schemaModeData->ViewPitchMax;
	}
}

// 카메라 회전 처리 접근
TWeakPtr<FHcCameraRotationBase> FHcCameraModeBase::GetCameraRotationBase()
{
	TWeakPtr<IHcCameraWork> work = GetCameraWork(EHcCameraWorkType::RotationWork);
	if (work == nullptr)
	{
		return nullptr;
	}

	TSharedPtr<IHcCameraWork> baseSharedPtr = work.Pin();
	if (baseSharedPtr.IsValid() == false)
	{
		return nullptr;
	}

	TSharedPtr<FHcCameraRotationBase> derivedSharedPtr =
		StaticCastSharedPtr<FHcCameraRotationBase>(baseSharedPtr);


	if (derivedSharedPtr.IsValid() == false)
	{
		return nullptr;
	}

	return derivedSharedPtr;
}

// 카메라 기능 접근
TWeakPtr<IHcCameraWork> FHcCameraModeBase::GetCameraWork(EHcCameraWorkType In_type)
{
	TWeakPtr<IHcCameraWork> work = _mapCamWorks.FindRef(In_type);
	return work;
}