#pragma once
#include "BaseDecision.h"

class DecisionPrint : public BaseDecision
{
public:
	DecisionPrint();
	virtual ~DecisionPrint();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

private:
	float m_fTimer;
};

