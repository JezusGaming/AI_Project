#include "Idle.h"
#include "AIStateMachine.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
Idle::Idle()
{
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Idle::~Idle()
{
}

//----------------------------------------------------------------------------
// Sets variables to a starting num when entering almost used as a constructor
// Param:
//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
//----------------------------------------------------------------------------
void Idle::OnEnter(AIStateMachine* pMachine)
{
	fTimer = 0.0f;
}

//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call
//		Agent: is a pointer to the agent which will use this function
//		pMachine: pointer to AIStateMachine to use statemachine functions
// Return:
//		
//----------------------------------------------------------------------------
void Idle::OnUpdate(float deltaTime, Agent* agent, AIStateMachine* pMachine)
{
	
	fTimer += deltaTime;
	// changes state after 3 seconds
	if (fTimer >= 3.0f)
	{
		pMachine->PushState(1);
	}
}

//----------------------------------------------------------------------------
// draws textures for this class
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void Idle::OnDraw(Renderer2D* m_2dRenderer)
{
}

//----------------------------------------------------------------------------
//  Sets variables to a starting or ending num when exiting
// Param:
//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
//----------------------------------------------------------------------------
void Idle::OnExit(AIStateMachine* pMachine)
{
	fTimer = 0.0f;
}