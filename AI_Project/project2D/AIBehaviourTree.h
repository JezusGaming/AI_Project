#pragma once

class BehaviourNode;

class AIBehaviourTree
{
public:
	AIBehaviourTree();
	~AIBehaviourTree();

	void Update(float fDeltaTime);

	BehaviourNode* m_pRoot;

};

