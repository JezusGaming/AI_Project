#include "ControlledPlayer.h"
#include "Controlled.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
ControlledPlayer::ControlledPlayer()
{
	// creates a stateMachine which does keyboard behaviour 
	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);
	m_pAIStateMachine->AddState(0, new Controlled());
	m_pAIStateMachine->PushState(0);
	// sets start pos
	m_pos.x = 200.0f;
	m_pos.y = 200.0f;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
ControlledPlayer::~ControlledPlayer()
{
	delete m_pAIStateMachine;
}

//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call
//----------------------------------------------------------------------------
void ControlledPlayer::Update(float deltaTime)
{
	// updates statemachine
	m_pAIStateMachine->Update(deltaTime, this);
}

//----------------------------------------------------------------------------
// draws textures for this class and sets camera
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void ControlledPlayer::Draw(aie::Renderer2D * m_2dRenderer)
{
	// draws a green box
	m_2dRenderer->setRenderColour(0x00FF00FF);
	m_2dRenderer->drawBox(m_pos.x, m_pos.y, 30, 30);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
