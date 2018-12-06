#include "Patrol.h"
#include "FollowBehaviour.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
Patrol::Patrol()
{
	// pushs behaviours being used onto behaviour list
	m_behaviours.PushFront(new FollowBehaviour(0.0f));
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Patrol::~Patrol()
{
	// deletes behaviours, and behaviour list
	for (unsigned int i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

//----------------------------------------------------------------------------
// Sets variables to a starting num when entering almost used as a constructor
// Param:
//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
//----------------------------------------------------------------------------
void Patrol::OnEnter(AIStateMachine* pMachine)
{
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
void Patrol::OnUpdate(float deltaTime, Agent* agent, AIStateMachine* pMachine)
{
	// updates behaviours
	for (int i = 0; i < m_behaviours.Size(); ++i)
	{
		m_behaviours[i]->Update(agent, deltaTime);
	}
}

//----------------------------------------------------------------------------
// draws textures for this class
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void Patrol::OnDraw(Renderer2D* m_2dRenderer)
{
	
}

//----------------------------------------------------------------------------
//  Sets variables to a starting or ending num when exiting
// Param:
//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
//----------------------------------------------------------------------------
void Patrol::OnExit(AIStateMachine* pMachine)
{
}
