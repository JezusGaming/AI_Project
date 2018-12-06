#pragma once
#include "IBehaviour.h"

class Arrive : public IBehaviour
{
public:

	//----------------------------------------------------------------------------
	// default constructor which sets a wieght for the behaviour, inherited from 
	// Ibehaviour
	//----------------------------------------------------------------------------
	Arrive(float fWieghting);

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~Arrive();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//		Agent: is a pointer to the agent which will use this function
	//
	// Return:
	//		has to return a vector2 so it is returning a default vector
	//----------------------------------------------------------------------------
	Vector2 Update(Agent* agent, float deltaTime);
};

