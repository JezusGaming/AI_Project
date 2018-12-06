#pragma once
#include "IBehaviour.h"
class Wander : public IBehaviour
{
public:
	//----------------------------------------------------------------------------
	// default constructor which sets a wieght for the behaviour, inherited from 
	// Ibehaviour
	//----------------------------------------------------------------------------
	Wander(float fWieghting);

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~Wander();

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
	Vector2 Update(Agent* agent, float deltaTime);

	//----------------------------------------------------------------------------
	// Returns a random number used for wander update
	//----------------------------------------------------------------------------
	float RandNum();

private:
	// initializes variables
	float m_fWanderRadius;
	float m_fWanderJitter;
	float m_fWanderDistance;
};

