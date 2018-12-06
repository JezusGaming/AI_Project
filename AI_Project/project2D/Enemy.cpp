#include "Enemy.h"
#include "MoveState.h"
using namespace aie;

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
Enemy::Enemy()
{
	// creates a stateMachine which does keyboard behaviour 
	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);
	m_pAIStateMachine->AddState(0, new MoveState());
	m_pAIStateMachine->PushState(0);
	// sets start pos
	m_pos.x = 200;
	m_pos.y = 200;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Enemy::~Enemy()
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
void Enemy::Update(float deltaTime)
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
void Enemy::Draw(aie::Renderer2D * m_2dRenderer)
{
	// draws a red circle
	m_2dRenderer->setRenderColour(0xFF0000FF);
	m_2dRenderer->drawCircle(m_pos.x, m_pos.y, 30, 30);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
