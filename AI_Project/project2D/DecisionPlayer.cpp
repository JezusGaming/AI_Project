#include "DecisionPlayer.h"
#include "DecisionButtonPressed.h"
#include "ASeek.h"
#include "AFlee.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
DecisionPlayer::DecisionPlayer()
{
	// creates a decisiontree which does seek or flee
	m_pRoot = new DecisionButtonPressed();
	m_pRoot->m_pTrueDecision = new AFlee();
	m_pRoot->m_pFalseDecision = new ASeek();
	m_pos.x = 200;
	m_pos.y = 200;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
DecisionPlayer::~DecisionPlayer()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call
//----------------------------------------------------------------------------
void DecisionPlayer::Update(float fDeltaTime)
{
	// updates the player and makes a decision on what behaviour to do
	m_pRoot->MakeDecision(this, fDeltaTime);
}

//----------------------------------------------------------------------------
// draws textures for this class and sets camera
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void DecisionPlayer::Draw(aie::Renderer2D * m_2dRenderer)
{
	// draws a blue box
	m_2dRenderer->setRenderColour(0x0000FFFF);
	m_2dRenderer->drawBox(m_pos.x, m_pos.y, 30, 30);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
