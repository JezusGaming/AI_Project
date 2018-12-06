#pragma once
#include "Agent.h"
#include "Renderer2D.h"

class ControlledPlayer : public Agent
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	ControlledPlayer();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~ControlledPlayer();

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
	void Draw(aie::Renderer2D*	m_2dRenderer);

private:
	AIStateMachine* m_pAIStateMachine;
};

