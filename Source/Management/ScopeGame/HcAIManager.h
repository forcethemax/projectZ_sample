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

	

public:
	// 초기화(처음 한번만)
	virtual void Initialize() override;
	// 해제
	virtual void Finalize() override;
	
private:
	// ai 데이터 로드
	void LoadAIData();
};

#define HcAI() UHcScopeHolder::GetGameManagerFType<FHcAIManager>(UHcScopeGame::EManagerType::AI)