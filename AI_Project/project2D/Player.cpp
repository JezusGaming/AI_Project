#include "Player.h"
#include "Patrol.h"
#include "Idle.h"

using namespace aie;

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
Player::Player()
{
	// creates a stateMachine which does keyboard behaviour 
	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);
	m_pAIStateMachine->AddState(0, new Idle());
	m_pAIStateMachine->AddState(1, new Patrol());
	m_pAIStateMachine->PushState(0);
	// sets start pos of the player and the start and end path for this player
	m_pos.x = 450;
	m_pos.y = 150;
	m_nStart = 1;
	m_nEnd = 98;
}
//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Player::~Player()
{
	delete m_pAIStateMachine;
}

//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call in milliseconds
//----------------------------------------------------------------------------
void Player::Update(float deltaTime)
{
	// updates statemachine
	m_pAIStateMachine->Update(deltaTime, this);
}

//----------------------------------------------------------------------------
// draws textures for this class
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void Player::Draw(aie::Renderer2D*	m_2dRenderer)
{
	// draws a white box
	m_2dRenderer->drawBox(m_pos.x, m_pos.y, 30, 30);
}
