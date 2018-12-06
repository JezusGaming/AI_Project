#pragma once
#include "Vector2.h"

class Agent;

class IBehaviour
{
public:
	//----------------------------------------------------------------------------
	// lets all Behaviours have a wieght so behaviours can be used together
	//----------------------------------------------------------------------------
	IBehaviour(float fWieghting) 
	{
		m_fWeighting = fWieghting;
	};

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~IBehaviour() {};

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//		Agent: is a pointer to the agent which will use this function
	//
	// Return:
	//		Returns a Vector2
	//----------------------------------------------------------------------------
	virtual Vector2 Update(Agent* agent, float deltaTime) = 0;

	// starts wieghting at zero
	float m_fWeighting = 0;
};

