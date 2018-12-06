#pragma once
#include "Agent.h"
#include "DecisionQuestion.h"

class Seek;
class Flee;

class DecisionPlayer : public Agent
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	DecisionPlayer();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~DecisionPlayer();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//----------------------------------------------------------------------------
	void Update(float fDeltaTime);

	//----------------------------------------------------------------------------
	// draws textures for this class and sets camera
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	void Draw(aie::Renderer2D * m_2dRenderer);

private:
	DecisionQuestion* m_pRoot;
};

