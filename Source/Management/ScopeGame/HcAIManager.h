#pragma once

#include "Classes/HcManager.h"

#include "Management/HcMessageHolder.h"
#include "Management/HcScopeGame.h"

#include "AI/Define/HcAIDefine.h"

class FHcAITaskResolver;

class FHcAIManager:
	public IHcManager
{
private:
	TMap<EHcAIContentsType, TSharedPtr<FHcAITaskResolver>> _mapTaskResolver;
};

#define HcAI() UHcScopeHolder::GetGameManagerFType<FHcAIManager>(UHcScopeGame::EManagerType::AI)