#include "Grid.h"
#include "Defines.h"
#include "GridNode.h"
#include "AStar.h"
#include "DynamicArray.h"
#include "AStarNode.h"

struct GridNode;
Grid* Grid::m_pInstance = nullptr;

int Heuristic(AStarNode * pNode, AStarNode * pEnd)
{
	//diagonal shorcut method
	int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;
	difX = abs(difX);
	difY = abs(difY);

	if (difX > difY)
		return (14 * difY) + 10 * (difX - difY);
	else
		return (14 * difX) + 10 * (difY - difX);

	//manhattan method
	// return (difX + difY) * 10;
}

Grid::Grid()
{
	m_ppGrid = new GridNode*[GRID_SIZE * GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{

			int index = (y * GRID_SIZE) + x;

			Vector2 pos(400 + x * NODE_SIZE, 150 + y * NODE_SIZE);

			m_ppGrid[index] = new GridNode(pos, index, x, y);
			if (x % 3 == 0 && y != 5)
			{
				m_ppGrid[index]->m_bBlocked = true;
			}
		}
	}
	//connect up adjeacent nodes
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;
			GridNode* currentNode = m_ppGrid[index];



			//adjacent nodes 
			for (int a = 0; a < 4; ++a)
			{
				//work out adjacent nodes
				int localX = x;
				int localY = y;

				if (a % 2 == 0)
				{
					localX += a - 1;
				}
				else
				{
					localY += a - 2;
				}

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				//connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = ADJACENT_COST;

				currentNode->m_AdjacentList.PushBack(pEdge);

			}

			//diagonal nodes
			// -------------
			// | 1 |   | 2 |
			// -------------
			// |   | C |   |
			// -------------
			// | 0 |   | 3 |
			// -------------
			for (int d = 0; d < 4; ++d)
			{
				int localX = x;
				int localY = y;

				if (d % 2 == 0)
				{
					localX += d - 1;
					localY += d - 1;
				}
				else
				{
					localX += d - 2;
					localY -= d - 2;
				}
				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				//connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = DIAGNAL_COST;

				currentNode->m_AdjacentList.PushBack(pEdge);
			}
		}
	}

	//setup AStar
	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	m_pAStar->SetFunction(&Heuristic);
}


Grid::~Grid()
{
	delete m_pAStar;
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}
	delete[] m_ppGrid;
}

void Grid::Draw(aie::Renderer2D*	m_2dRenderer)
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;

		if (m_ppGrid[i]->m_bBlocked)
			m_2dRenderer->setRenderColour(0x303030FF);
		else
			m_2dRenderer->setRenderColour(0x808080FF);

		m_2dRenderer->drawBox(x, y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);

		//draw adjacency
		for (int a = 0; a < m_ppGrid[i]->m_AdjacentList.Size(); ++a)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

			float otherX = otherNode->m_v2Pos.x;
			float otherY = otherNode->m_v2Pos.y;
			m_2dRenderer->setRenderColour(0xFF0000FF);
			m_2dRenderer->drawLine(x, y, otherX, otherY, EDGE_THICKNESS);
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}
	}

	//draws path
	/*DynamicArray<AStarNode*> path;
	m_pAStar->CalculatePath(m_ppGrid[22], m_ppGrid[67], &path);

	for (int i = 0; i < path.Size(); ++i)
	{
		GridNode* pNode = (GridNode*)path[i];

		m_2dRenderer->setRenderColour(0x00FF00FF);
		m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	}*/
	
}

GridNode* Grid::GetGrid(int nIndex)
{
	return m_ppGrid[nIndex];
}

//----------------------------------------------------------------------------
// creates a new Grid
//----------------------------------------------------------------------------
void Grid::Create()
{
	if (!m_pInstance)
	{
		m_pInstance = new Grid();
	}
}

//----------------------------------------------------------------------------
// deletes a Grid
//----------------------------------------------------------------------------
void Grid::Destroy()
{
	delete m_pInstance;
}

//----------------------------------------------------------------------------
// returns a grid
//----------------------------------------------------------------------------
Grid* Grid::GetInstance()
{
	return m_pInstance;
}


