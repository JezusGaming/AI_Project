#pragma once
#include "Composite.h"

//and
class Sequence : public Composite
{
	EBehaviourResult Execute()
	{
		BehaviourNode* child = PendingNode;

		unsigned int i = -1;
		if (!child)
		{
			i = 0;
		}

		for (; i < children.Size(); ++i)
		{
			if (i >= 0)
			{
				child = children[i];
			}

			EBehaviourResult result = child->Execute();
			if (result == EBEHAVIOUR_FAILURE)
			{
				PendingNode = nullptr;
				return EBEHAVIOUR_FAILURE;
			}
			if (result == EBEHAVIOUR_PENDING)
			{
				PendingNode = child;
				return EBEHAVIOUR_PENDING;
			}
		}
		PendingNode = nullptr;
		return EBEHAVIOUR_SUCCESS;
	}
};