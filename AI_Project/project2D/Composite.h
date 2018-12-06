#pragma once
#include "BehaviourNode.h"
#include "DynamicArray.h"

class Composite : public BehaviourNode
{
public:
	virtual ~Composite()
	{
		for (unsigned int i = 0; i < children.Size(); ++i)
		{
			delete children[i];
		}
	};

	DynamicArray<BehaviourNode*> children;

	BehaviourNode* PendingNode = nullptr;
};
