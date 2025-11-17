#pragma once

#include "Classes/HcManager.h"

#include "Management/HcMessageHolder.h"
#include "Management/HcScopeGame.h"

#include "AI/Define/HcAIDefine.h"

class FHcAITaskResolver;
class FHcAIStateManager;

class FHcAIManager:
	public IHcManager
{
private:
	TSharedPtr<FHcAIStateManager> _stateManager;
	
	TMap<EHcAIContentsType, TSharedPtr<FHcAITaskResolver>> _mapTaskResolver;

	// 현재 컨텐츠 타입
	EHcAIContentsType _currentContentsType = EHcAIContentsType::Auto_off;	
	
	bool _isAIOn = false;

public:
	// 초기화(처음 한번만)
	virtual void Initialize() override;
	// 해제
	virtual void Finalize() override;
	
private:
	// ai 데이터 로드
	void LoadAIData();
	
	void SetAIOnOff(bool In_isOn);
	
public:
	// 컨텐츠 타입 변경
	void ChangeContentsType(EHcAIContentsType In_type);
	
	// 자동 사냥 이펙트 중지
	void StopAutoPlayEnv(){}
};

#define HcAI() UHcScopeHolder::GetGameManagerFType<FHcAIManager>(UHcScopeGame::EManagerType::AI)