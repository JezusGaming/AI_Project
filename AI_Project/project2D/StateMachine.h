#pragma once
#include "DynamicArray.h"
#include "Stack.h"
#include "BaseState.h"
#include "Renderer2D.h"

using namespace aie;
class StateMachine
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	StateMachine();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~StateMachine();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//----------------------------------------------------------------------------
	void Update(float deltaTime);

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
	void AddState(int nStateIndex, BaseState* pState);

private:
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_CurrentStack;
};

