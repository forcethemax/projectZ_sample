#include "HcAIBaseState.h"

#include "AI/Define/HcAIDefine.h"

FHcAIBaseState::FHcAIBaseState() : THcState<EHcAIActionType>(EHcAIActionType::WAIT)
{
}
