#pragma once
#include "Agent.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include "AStar.h"
#include "Grid.h"

using namespace aie;

class FollowBehaviour : public IBehaviour
{
public:
	//----------------------------------------------------------------------------
	// default constructor which sets a wieght for the behaviour, inherited from 
	// Ibehaviour
	//----------------------------------------------------------------------------
	FollowBehaviour(float fWieghting);

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~FollowBehaviour();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//		Agent: is a pointer to the agent which will use this function
	//
	// Return:
	//		Returns a Vector2
	//----------------------------------------------------------------------------
	Vector2 Update(Agent* agent, float deltaTime);


protected:
	AStar* m_pAStar;
	Grid* m_pGrid;
	DynamicArray<AStarNode*> m_path;
	int m_nNextNode;
};

