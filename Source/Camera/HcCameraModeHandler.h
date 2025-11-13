#pragma once 

#include "Classes/HcStateManager.h"

#include "Camera/Mode/HcCameraModeBase.h"

enum class EHcCameraMode : uint8;
enum class EHcCameraInitModeType : uint8;

class AplayDemoZNCharacter;

// 카메라 모드 할당 관리자
class FHcCameraModeAllocator : public THcSharedObjectMapAllocator<EHcCameraMode, FHcCameraModeBase>
{
public:
	FHcCameraModeAllocator(){}
	virtual ~FHcCameraModeAllocator(){}
	virtual FHcCameraModeBase* Alloc(EHcCameraMode In_mode) override;
};

class FHcCameraModeHandler: public THcStateManager<FHcCameraModeBase, FHcCameraModeAllocator>,
	public TSharedFromThis<FHcCameraModeHandler>
{
	// 타입 별칭 선언
	using Super = THcStateManager<FHcCameraModeBase, FHcCameraModeAllocator>;

	// 멤버 변수
private:
	AplayDemoZNCharacter* _playDemoZNCharacter;

	// 스폰할 대 초기화 하는 모드 변환인지
	bool _isSpawnInitModeChange = true;
	// 가상 함수
public:
	virtual ~FHcCameraModeHandler() = default;

	virtual void ChangeState(TStateType In_state) override;

public:
	void Finalize();

	void Initialize(AplayDemoZNCharacter* In_playDemoZNCharacter);

	// get,set
public:
	// 초기화 모드 타입 구하기
	EHcCameraInitModeType GetInitModeType();
};