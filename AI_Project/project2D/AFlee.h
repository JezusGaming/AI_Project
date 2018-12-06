#pragma once
#include "BaseDecision.h"
#include "DynamicArray.h"
#include "IBehaviour.h"
class Agent;

class AFlee : public BaseDecision
{
public:
	AFlee();
	~AFlee();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

protected:
	DynamicArray<IBehaviour*> m_behaviours;
};

