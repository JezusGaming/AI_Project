#include "DecisionTree.h"
#include "DecisionButtonPressed.h"
#include "DecisionNothingPressed.h"
#include "DecisionPrint.h"
//move to player is like stae but has a q and a
DecisionTree::DecisionTree()
{
	m_pRoot = new DecisionButtonPressed();
	m_pRoot->m_pTrueDecision = new DecisionPrint();
	m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
}


DecisionTree::~DecisionTree()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

void DecisionTree::Update(Agent * pAgent, float fDeltaTime)
{
	m_pRoot->MakeDecision(pAgent, fDeltaTime);
}
