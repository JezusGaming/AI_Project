#pragma once
#include "DynamicArray.h"
#include "Stack.h"
#include "AIState.h"
#include "Renderer2D.h"

using namespace aie;
class AIStateMachine
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	AIStateMachine();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~AIStateMachine();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//		agent: is a pointer to an entity so it can access it pos and more
	//----------------------------------------------------------------------------
	void Update(float deltaTime, Agent* agent);

	//----------------------------------------------------------------------------
	// draws textures for this class and sets camera
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//----------------------------------------------------------------------------
	// pushs to the stateIndex
	//
	// param:
	//		nStateIndex: the Indedx of a state you want to go to
	//----------------------------------------------------------------------------
	void PushState(int nStateIndex);

	//----------------------------------------------------------------------------
	// pops the current state off
	//----------------------------------------------------------------------------
	void PopState();

	//----------------------------------------------------------------------------
	// Adds a state with an stateIndex
	//
	// param:
	//		nStateIndex: the Indedx of a state
	//		pState: is the name of a state that has been created
	//----------------------------------------------------------------------------
	void AddState(int nStateIndex, AIState* pState);

private:
	DynamicArray<AIState*> m_StateList;
	Stack<AIState*> m_CurrentStack;
};

