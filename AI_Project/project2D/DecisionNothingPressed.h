#pragma once
#include "BaseDecision.h"
class DecisionNothingPressed : public BaseDecision
{
public:
	DecisionNothingPressed();
	~DecisionNothingPressed();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

};

