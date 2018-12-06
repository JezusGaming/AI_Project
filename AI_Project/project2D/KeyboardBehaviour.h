#pragma once
#include "IBehaviour.h"
#include "Agent.h"
#include "Matrix3.h"

class KeyboardBehaviour : public IBehaviour
{
public:

	//----------------------------------------------------------------------------
	// default constructor which sets a wieght for the behaviour, inherited from 
	// Ibehaviour
	//----------------------------------------------------------------------------
	KeyboardBehaviour(float fWieghting);

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~KeyboardBehaviour();

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

private:
	// initializes variables
	Vector2 dir;
	Vector2 vel;
	float mass;
	float drag;
	float speed;
};

