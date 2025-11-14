#pragma once

#include "AI/State/HcAIBaseState.h"

// ai 상태: 대기 상태(조건 업데이트)

class FHcAIStateIdle final: public FHcAIBaseState
{
public:
	virtual ~FHcAIStateIdle() = default;
	
public:
	virtual void Update(float In_deltaTime) override;
};