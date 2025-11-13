#include "Camera/HcCameraModeHandler.h"

#include "Camera/Mode/HcCameraModeBackView.h"
#include "Camera/Mode/HcCameraModeQuarter.h"

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