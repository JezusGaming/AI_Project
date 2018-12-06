#include "MoveState.h"
#include "Seek.h"
#include "Flee.h"
#include "Agent.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
MoveState::MoveState()
{
	// pushs behaviours being used onto behaviour list
	m_behaviours.PushFront(new Seek(1.0f));
	m_behaviours.PushFront(new Flee(0.5f));
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
MoveState::~MoveState()
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
void MoveState::OnEnter(AIStateMachine * pMachine)
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
void MoveState::OnUpdate(float deltaTime, Agent * agent, AIStateMachine * pMachine)
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

	agent->SetPos(agent->GetPos() + v2TotalForce);

}

//----------------------------------------------------------------------------
// draws textures for this class
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void MoveState::OnDraw(Renderer2D * m_2dRenderer)
{
}

//----------------------------------------------------------------------------
//  Sets variables to a starting or ending num when exiting
// Param:
//		pMachine: pointer to AIStateMachine, lets us push, pop, and more
//----------------------------------------------------------------------------
void MoveState::OnExit(AIStateMachine * pMachine)
{
}
