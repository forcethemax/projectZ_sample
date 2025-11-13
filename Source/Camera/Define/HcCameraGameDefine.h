#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHcCameraMode : uint8
{
	BackView = 0,
	Quarter = 1,
};

// 카메라 기능 타입
enum class EHcCameraWorkType : uint8
{
	LocationWork,
	RotationWork,
	OffsetWork,			 // 스프링암의 소켓 오프셋
	ZoomWork,
	FOVWork,		
	DOFWork,
	TargetOffsetWork,	// 스프링암의 타겟 오프셋
	
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