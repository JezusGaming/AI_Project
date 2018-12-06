#pragma once
#include "IBehaviour.h"

class Flee : public IBehaviour
{
public:
	//----------------------------------------------------------------------------
	// default constructor which sets a wieght for the behaviour, inherited from 
	// Ibehaviour
	//----------------------------------------------------------------------------
	Flee(float fWieghting);

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~Flee();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//		Agent: is a pointer to the agent which will use this function
	//
	// Return:
	//		Returns equation to flee
	//----------------------------------------------------------------------------
	Vector2 Update(Agent* agent, float deltaTime);
};

