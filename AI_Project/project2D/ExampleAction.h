#pragma once
#include "BehaviourNode.h"
#include <iostream>

class ExampleAction : public BehaviourNode
{
public:
	ExampleAction(char* text)
	{
		m_szText = text;
	}

	EBehaviourResult Execute()
	{
		std::cout << m_szText << std::endl;
		return EBEHAVIOUR_SUCCESS;
	}
private:
	char* m_szText;
};