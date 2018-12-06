#pragma once

class Agent;
class BaseDecision
{
public:
	virtual void MakeDecision(Agent* pAgent, float fDeltaTime) = 0;
};