#include "Wander.h"
#include "Agent.h"
#include <stdlib.h>  
#include <time.h> 

//----------------------------------------------------------------------------
// default constructor which sets a wieght for the behaviour, inherited from 
// Ibehaviour
//----------------------------------------------------------------------------
Wander::Wander(float fWieghting) : IBehaviour(fWieghting)
{
	m_fWanderJitter = 0.1f;
	m_fWanderRadius = 80.0f;
	m_fWanderDistance = 220.0f;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Wander::~Wander()
{
}

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
Vector2 Wander::Update(Agent* agent, float deltaTime)
{
	// sets wander target to a random amount with jitter
	Vector2 m_v2WanderTarget;
	m_v2WanderTarget += Vector2(RandNum() * m_fWanderJitter, RandNum() * m_fWanderJitter);
	m_v2WanderTarget.Normalise();

	// sets radius of target
	m_v2WanderTarget = m_v2WanderTarget * m_fWanderRadius;

	// sets targetworld to a spot the agent is facing
	Vector2 targetWorld = m_v2WanderTarget + agent->GetFacing() * m_fWanderDistance;
	targetWorld.Normalise();

	// returns wander movement
	return targetWorld;
}

//----------------------------------------------------------------------------
// Returns a random number used for wander update
//----------------------------------------------------------------------------
float Wander::RandNum()
{
	return rand()% 3-1;
}

