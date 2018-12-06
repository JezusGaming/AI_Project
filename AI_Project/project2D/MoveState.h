#pragma once
#include "AIState.h"
class MoveState : public AIState
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	MoveState();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~MoveState();

	//----------------------------------------------------------------------------
	// Sets variables to a starting num when entering almost used as a constructor
	// Param:
	//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
	//----------------------------------------------------------------------------
	void OnEnter(AIStateMachine* pMachine);

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
	void OnUpdate(float deltaTime, Agent* agent, AIStateMachine* pMachine);

	//----------------------------------------------------------------------------
	// draws textures for this class
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);

	//----------------------------------------------------------------------------
	//  Sets variables to a starting or ending num when exiting
	// Param:
	//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
	//----------------------------------------------------------------------------
	void OnExit(AIStateMachine* pMachine);

private:
};

