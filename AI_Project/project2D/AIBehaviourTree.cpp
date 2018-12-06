#include "AIBehaviourTree.h"
#include "ExampleAction.h"
#include "ExampleQuestion.h"
#include "Selector.h"
#include "Sequence.h"
#include "BehaviourNode.h"

AIBehaviourTree::AIBehaviourTree()
{
	m_pRoot = new Selector();

	//lhs
	BehaviourNode* pFirst = new Sequence();
	BehaviourNode* pFirstFirst = new ExampleQuestion();
	BehaviourNode* pFirstSecond = new ExampleAction("Button Pressed");
	((Composite*)pFirst)->children.PushBack(pFirstFirst);
	((Composite*)pFirst)->children.PushBack(pFirstSecond);

	//rhs
	BehaviourNode* pSecond = new ExampleAction("Button not Pressed");
	((Composite*)m_pRoot)->children.PushBack(pFirst);
	((Composite*)m_pRoot)->children.PushBack(pSecond);
}

AIBehaviourTree::~AIBehaviourTree()
{
	delete m_pRoot;
}

void AIBehaviourTree::Update(float fDeltaTime)
{
	m_pRoot->Execute();
}
