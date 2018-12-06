#include "WanderState.h"
#include "Wander.h"
#include "Agent.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
WanderState::WanderState()
{
	// pushs behaviours being used onto behaviour list
	m_behaviours.PushFront(new Wander(1.0f));
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
WanderState::~WanderState()
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
void WanderState::OnEnter(AIStateMachine * pMachine)
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
void WanderState::OnUpdate(float deltaTime, Agent * agent, AIStateMachine * pMachine)
{
	Vector2 v2TotalForce;
	// updates behaviours, and Truncates them, then sets the position
	for (int i = 0; i < m_behaviours.Size(); ++i)
	{
		Vector2 currentForce = m_behaviours[i]->Update(agent, deltaTime);
		currentForce = currentForce * m_behaviours[i]->m_fWeighting;

		v2TotalForce = v2TotalForce + currentForce;

		float fMagnitude = v2TotalForce.Magnitude();
		if (fMagnitude > 10.0f)
		{
			v2TotalForce.Normalise();
			v2TotalForce = v2TotalForce * 10.0f;
			break;
		}
	}
	// sets which way agent is facing
	Vector2 m_faceing;
	m_faceing = v2TotalForce;
	m_faceing.Normalise();
	agent->SetFacing(m_faceing);

	agent->SetPos(agent->GetPos() + v2TotalForce * 50 * deltaTime);
}

//----------------------------------------------------------------------------
// draws textures for this class
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void WanderState::OnDraw(Renderer2D * m_2dRenderer)
{
}

//----------------------------------------------------------------------------
//  Sets variables to a starting or ending num when exiting
// Param:
//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
//----------------------------------------------------------------------------
void WanderState::OnExit(AIStateMachine * pMachine)
{
}
