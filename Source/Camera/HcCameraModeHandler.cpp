#include "Camera/HcCameraModeHandler.h"

#include "playDemoZNCharacter.h"
#include "Camera/Mode/HcCameraModeBackView.h"
#include "Camera/Mode/HcCameraModeQuarter.h"
#include "Camera/Mode/HcCameraModeDialog.h"

#include "Camera/Define/HcCameraGameDefine.h"

#include "Management/ScopeGame/HcCameraModeManager.h"

// 할당
FHcCameraModeBase* FHcCameraModeAllocator::Alloc(EHcCameraMode In_mode)
{
	if (In_mode == EHcCameraMode::BackView)
	{
		return new FHcCameraModeBackView();
	}
	else if (In_mode == EHcCameraMode::Quarter)
	{
		return new FHcCameraModeQuarter();
	}
	else if (In_mode == EHcCameraMode::Dialog)
	{
		return new FHcCameraModeDialog();
	}

	return nullptr;
}


void FHcCameraModeHandler::ChangeState(TStateType In_state)
{
	Super::ChangeState(In_state);

	EHcCameraMode camMode = (EHcCameraMode)In_state;
	HcCameraMode()->SetCurrentMode(camMode);
}

void FHcCameraModeHandler::Finalize()
{
	_playDemoZNCharacter = nullptr;

	TMap<EHcCameraMode, TSharedPtr<FHcCameraModeBase>> container = GetContainer();
	for (auto& iter: container)
	{
		iter.Value->Close();
	}
}

void FHcCameraModeHandler::Initialize(AplayDemoZNCharacter* In_playDemoZNCharacter)
{
	TArray<EHcCameraMode> arrMode;

	arrMode.Add(EHcCameraMode::BackView);
	arrMode.Add(EHcCameraMode::Quarter);
	arrMode.Add(EHcCameraMode::Dialog);

	// 캐릭터 세팅
	_playDemoZNCharacter = In_playDemoZNCharacter;

	for (auto& iter: arrMode)
	{
		auto makeObj = MakeInstance(iter);
		makeObj->Initialize();
		makeObj->SetModeTarget(In_playDemoZNCharacter);

		makeObj->SetModeHandler(AsShared());
	}
	FHcCameraModeManager* camManager = HcCameraMode();
	if (camManager == nullptr)
	{
		return;
	}
	EHcCameraMode newMode = camManager->GetCurrentMode();

	if (CurrentState.IsValid() == false ||
		CurrentState.Pin()->GetType() != newMode)
	{
		ChangeState(newMode);
	}
	else
	{
		CurrentState.Pin()->Exit();
		CurrentState.Pin()->Enter();
	}

	// 첫스폰 모드 처리 끝
	 _isSpawnInitModeChange = false;
}

// 초기화 모드 타입 구하기
EHcCameraInitModeType FHcCameraModeHandler::GetInitModeType()
{
	if (_isSpawnInitModeChange == false)
	{
		return EHcCameraInitModeType::ModeChange;
	}

	return EHcCameraInitModeType::SameMapSpawn;
}

void FHcCameraModeHandler::OnCameraDialogStart(bool In_isUserSpotIdPos,
bool In_isZoomFirstCameraMove)
{
	if (HcCameraMode()->GetCurrentMode() == EHcCameraMode::Dialog)
	{
		return;
	}
	
	bool isUserSoptIdPos = In_isUserSpotIdPos;
	SetLocalUseSpotIdPos(isUserSoptIdPos);
	
	HcCameraMode()->SetIsUseCutFadeOut(isUserSoptIdPos);
	HcCameraMode()->SetIsZoomFirstCameraMove(In_isZoomFirstCameraMove);
}

void FHcCameraModeHandler::SetLocalUseSpotIdPos(bool In_isUse)
{
	if (In_isUse == false)
	{
		return;
	}
	// 이전은 안쓰고 이제 쓰면 백업 하자
	if (_isUserSpotIdPos == false)
	{
		_isUserSpotIdPos = true;
		
		// 카메라를 떼고 처리해야함
		// 나중에 때면 이상한 각도에서 나옴(바로 세팅시)
		SetAttachFollowCamera(false);
		
		if (_playDemoZNCharacter.IsValid() == false)
		{
			return;
		}
		
		_backupLocalPos = _playDemoZNCharacter->GetActorLocation();
	}
}

void FHcCameraModeHandler::SetAttachFollowCamera(bool In_isAttach)
{
	if (_playDemoZNCharacter.IsValid() == false)
	{
		return;
	}
	_playDemoZNCharacter->SetAttachFollowCamera(In_isAttach);
	
}