#include "WanderPlayer.h"
#include "WanderState.h"
#include "Idle.h"

using namespace aie;

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
WanderPlayer::WanderPlayer()
{
	// creates a stateMachine which does keyboard behaviour 
	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);
	m_pAIStateMachine->AddState(0, new Idle());
	m_pAIStateMachine->AddState(1, new WanderState());
	m_pAIStateMachine->PushState(0);
	// sets start pos
	m_pos.x = 900;
	m_pos.y = 350;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
WanderPlayer::~WanderPlayer()
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
void WanderPlayer::Update(float deltaTime)
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
void WanderPlayer::Draw(aie::Renderer2D * m_2dRenderer)
{
	// draws a yellow box
	m_2dRenderer->setRenderColour(0xFFF200FF);
	m_2dRenderer->drawBox(m_pos.x, m_pos.y, 30, 30);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
