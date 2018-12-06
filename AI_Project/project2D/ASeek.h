#pragma once
#include "DynamicArray.h"
#include "IBehaviour.h"
#include "BaseDecision.h"
class Agent;

class ASeek : public BaseDecision
{
public:
	ASeek();
	~ASeek();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

protected:
	DynamicArray<IBehaviour*> m_behaviours;
};

