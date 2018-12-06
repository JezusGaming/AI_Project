#include "AIStateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
AIStateMachine::AIStateMachine()
{	
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
AIStateMachine::~AIStateMachine()
{
	while (m_CurrentStack.Size() > 0)
	{
		PopState();
	}
	for (int i = 0; i < m_CurrentStack.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call
//		agent: is a pointer to an entity so it can access it pos and more
//----------------------------------------------------------------------------
void AIStateMachine::Update(float deltaTime, Agent* agent)
{
	if (m_CurrentStack.Size() <= 0)
	{
		return;
	}
	m_CurrentStack.Top()->OnUpdate(deltaTime, agent, this);
}

//----------------------------------------------------------------------------
// draws textures for this class and sets camera
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void AIStateMachine::Draw(Renderer2D * m_2dRenderer)
{
	if (m_CurrentStack.Size() <= 0)
	{
		return;
	}
	m_CurrentStack.Top()->OnDraw(m_2dRenderer);
}

//----------------------------------------------------------------------------
// pushs to the stateIndex
//
// param:
//		nStateIndex: the Indedx of a state you want to go to
//----------------------------------------------------------------------------
void AIStateMachine::PushState(int nStateIndex)
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	m_CurrentStack.PushBack(m_StateList[nStateIndex]);
	m_CurrentStack.Top()->OnEnter(this);
}

//----------------------------------------------------------------------------
// pops the current state off
//----------------------------------------------------------------------------
void AIStateMachine::PopState()
{
	if (m_CurrentStack.Size() > 0)
	{
		m_CurrentStack.Top()->OnExit(this);
	}

	m_CurrentStack.Pop();
	
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnEnter(this); 
}

//----------------------------------------------------------------------------
// Adds a state with an stateIndex
//
// param:
//		nStateIndex: the Indedx of a state
//		pState: is the name of a state that has been created
//----------------------------------------------------------------------------
void AIStateMachine::AddState(int nStateIndex, AIState* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}