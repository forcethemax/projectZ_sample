#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHcCameraMode : uint8
{
	BackView = 0 UMETA(Tooltip="자동시 따라다니는 카메라"),
	Quarter = 1 UMETA(Tooltip="쿼터뷰"),
	Boss = 2 UMETA(Tooltip="보스모드"),
	Dialog = 3 UMETA(Tooltip="대사 연출"),
	WarpStart = 4 UMETA(Tooltip="워프 연출 시작"),
	None = 5 UMETA(Tooltip="기본 값"),
	SpaceCrack = 6 UMETA(Tooltip="시공의 틈새 전용 카메라 모드"),
	FixedQuarter = 7 UMETA(Tooltip="고정형 쿼터"),
	PlayableEvent = 8 UMETA(Tooltip="플레이어블 이벤트 전용 카메라 모드"),
	EquipView = 9 UMETA(Tooltip="장비 뷰(hp 클릭시 나오는 것)"),
	DroneCam = 10 UMETA(Tooltip="촬영용 드론캠"),
	Max = 11,
};

// 카메라 기능 타입
enum class EHcCameraWorkType : uint8
{
	LocationWork,
	RotationWork,
	OffsetWork,			 // 스프링암의 소켓 오프셋
	ZoomWork,
	FOVWork,		
	BlurWork,
	DOFWork,
	TargetOffsetWork,	// 스프링암의 타겟 오프셋
	DialogCutLoopRotationWork,
	WarpStartRotationWork,
};

// 초기화 모드 타입
enum class EHcCameraInitModeType :uint8
{
	SameMapSpawn,		// 같은맵으로 스폰될때 처리(보간없이 세팅만)
	ModeChange,			// 모드 변환
};

// 줌 변환 타입
enum class EHcCameraChangeZoomType : uint8
{
	ModeChange,		// 모드 변환
	NoLerp,			// 보간 없이 세팅
};