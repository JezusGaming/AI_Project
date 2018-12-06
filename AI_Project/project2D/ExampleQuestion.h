#pragma once
#include "BehaviourNode.h"
#include "Input.h"
using namespace aie;

class ExampleQuestion : public BehaviourNode
{
	EBehaviourResult Execute()
	{
		if (Input::getInstance()->wasKeyPressed(INPUT_KEY_Q))
		{
			return EBEHAVIOUR_SUCCESS;
		}
		else
		{
			return EBEHAVIOUR_FAILURE;
		}
	}
};