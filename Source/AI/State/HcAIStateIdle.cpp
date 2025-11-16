#include "HcAIStateIdle.h"

#include "AI/HcAIStateManager.h"

void FHcAIStateIdle::Update(float In_deltaTime)
{
	TSharedPtr<FHcAIStateManager> shareStateManager = _aiStateManager.Pin();
	if (!shareStateManager.IsValid())
	{
		return;
	}
	shareStateManager->ProcessReserveJob();
}
