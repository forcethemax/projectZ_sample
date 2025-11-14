#include "AI/State/HcAIBaseState.h"

// ai 상태: 공격(검색, 이동, 공격 다처리)

class FHcAIStateAttackAnyone final : public FHcAIBaseState
{
public:
	virtual ~FHcAIStateAttackAnyone() = default;
	
public:
	virtual void Enter() override;	
	virtual void Update(float In_deltaTime) override;
};