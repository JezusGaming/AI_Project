#include "Flee.h"
#include "Input.h"
#include "Agent.h"
using namespace aie;

//----------------------------------------------------------------------------
// default constructor which sets a wieght for the behaviour, inherited from 
// Ibehaviour
//----------------------------------------------------------------------------
Flee::Flee(float fWieghting) : IBehaviour(fWieghting)
{
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Flee::~Flee()
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
//		Returns equation to flee
//----------------------------------------------------------------------------
Vector2 Flee::Update(Agent * agent, float deltaTime)
{
	// creates a point to flee from
	Vector2 v2FleePos(625.0f, 375.0f);
	// sets the dir
	Vector2 v2Dir = agent->GetPos() - v2FleePos;
	v2Dir.Normalise();
	// returns equation to flee
	return v2Dir * 100.0f * deltaTime;
}
