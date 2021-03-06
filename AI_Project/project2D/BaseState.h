#pragma once
#include "Renderer2D.h"
using namespace aie;

class StateMachine;

class BaseState
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	BaseState();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	virtual ~BaseState();

	//----------------------------------------------------------------------------
	// Sets variables to a starting num when entering almost used as a constructor
	// Param:
	//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
	//----------------------------------------------------------------------------
	virtual void OnEnter(StateMachine* pMachine) = 0;

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//		agent: is a pointer to an entity so it can access it pos and more
	//----------------------------------------------------------------------------
	virtual void OnUpdate(float deltaTime, StateMachine* pMachine) = 0;

	//----------------------------------------------------------------------------
	// draws textures for this class and sets camera
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;

	//----------------------------------------------------------------------------
	//  Sets variables to a starting or ending num when exiting
	// Param:
	//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
	//----------------------------------------------------------------------------
	virtual void OnExit(StateMachine* pMachine) = 0;

private:

};

