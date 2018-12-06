#pragma once
#include "DecisionQuestion.h"
//this is the question picks a behaviuor based on whats presed
class DecisionButtonPressed : public DecisionQuestion
{
public:
	DecisionButtonPressed();
	virtual ~DecisionButtonPressed();

	void MakeDecision(Agent* pAgent, float fDeltaTime);
};

