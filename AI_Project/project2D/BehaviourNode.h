#pragma once

enum EBehaviourResult
{
	EBEHAVIOUR_FAILURE = 0,
	EBEHAVIOUR_SUCCESS,
	EBEHAVIOUR_PENDING
};

class BehaviourNode
{
public:
	virtual ~BehaviourNode() {};
	virtual EBehaviourResult Execute() = 0;
};