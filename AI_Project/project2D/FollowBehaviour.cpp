#include "FollowBehaviour.h"
#include "Defines.h"
#include "GridNode.h"

//----------------------------------------------------------------------------
// default constructor which sets a wieght for the behaviour, inherited from 
// Ibehaviour
//----------------------------------------------------------------------------
FollowBehaviour::FollowBehaviour(float fWieghting) : IBehaviour(fWieghting)
{
	Grid* pGrid = Grid::GetInstance();

	m_pGrid = pGrid;

	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	m_nNextNode = 0;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
FollowBehaviour::~FollowBehaviour()
{
	delete m_pAStar;
}

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
Vector2 FollowBehaviour::Update(Agent* agent, float deltaTime)
{
	// clears path and calculates the path from the agents start and end
	m_path.Clear();
	m_pAStar->CalculatePath(m_pGrid->GetGrid(agent->SetStart()), m_pGrid->GetGrid(agent->SetEnd()), &m_path);
	// if nextnode is greater then path resets
	if (m_nNextNode >= m_path.Size())
		m_nNextNode = 0;

	// creates destination and direction using the grid and then sets agent pos
	Vector2 dest = ((GridNode*)m_path[m_nNextNode])->m_v2Pos;
	Vector2 dir = dest - agent->GetPos();
	dir.Normalise();
	agent->SetPos(agent->GetPos() + dir * 400.0f * deltaTime);

	//check distance and update when we get close to node
	Vector2 dist = dest - agent->GetPos();
	float fDist = dist.Magnitude();
	// moves to next node
	if (fDist < 10)
	{
		++m_nNextNode;
	}
	return Vector2(0, 0);
}

