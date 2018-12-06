#include "AStar.h"
#include "GridNode.h"
#include <math.h>

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
AStar::AStar(int nMaxNodes)
{
	m_ClosedList = new bool[nMaxNodes];
	m_nMaxNodes = nMaxNodes;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
AStar::~AStar()
{
	delete[] m_ClosedList;
}

void AStar::SetFunction(CalHeuristic func)
{
	calHeuristic = func;
}

int AStar::Callfunction(AStarNode* pNode, AStarNode* pEnd)
{
	if (calHeuristic)
		return calHeuristic(pNode, pEnd);

	return 0;
}

//----------------------------------------------------------------------------
// calculates a path to follow which is the cheapest to move
//
// Param:
//      pStart: pointer to AStarNode which is the start of the path 
//		pEnd: pointer to AStarNode which is the end of the path 
//		finishedPath: is a dynamicArray of the finished path using AStarNodes
//----------------------------------------------------------------------------
bool AStar::CalculatePath(AStarNode * pStart, AStarNode * pEnd, DynamicArray<AStarNode*>* finishedPath)
{
	//clear open list
	m_OpenList.Clear();
	//set all elements in closed list to false
	memset(m_ClosedList, 0, sizeof(bool) * m_nMaxNodes);

	//set start nodes g sorce to 0
	pStart->m_nGScore = 0;
	//calculate start nodes h score for now set to 0
	pStart->m_nHScore = Callfunction(pStart, pEnd);
	//calculate start nodes f score
	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;
	//set start nodes m_pPrev to null
	pStart->m_pPrev = nullptr;
	//Add start node to open list
	m_OpenList.Push(pStart);


	//while there are still nodes in the openlist
	while (m_OpenList.GetSize() > 0)
	{
		//get the node from the openlist with lowest f score we will call that currentnode
		AStarNode* currentNode = m_OpenList.Pop();

		//add currentnode to the closed list by setting the bool to true
		m_ClosedList[currentNode->m_nIndex] = true;

		//if currentnode is the end node we are finished	
		if (currentNode == pEnd)
		{
			//build path (remember it is backwards so we need to fix that)
			AStarNode* pNode = pEnd;
			do
			{
				finishedPath->PushFront(pNode);
				pNode = pNode->m_pPrev;
			}

			while (pNode);

			//return true to indicate that we found a valid path
			return true;
		}

		//loop through all currentnode's neighbours
		for (int i = 0; i < currentNode->m_AdjacentList.Size(); ++i)
		{
			
			AStarNode* pNiebghour = currentNode->m_AdjacentList[i]->m_pEndNode;
			int nCost = currentNode->m_AdjacentList[i]->m_nCost;

			//skip walls
			if (pNiebghour->m_bBlocked)
				continue;

			//skip neighbours that are already in the closed list
			if (m_ClosedList[pNiebghour->m_nIndex])
				continue;

			//if neighbour is already in open list...
			int heapindex = m_OpenList.contains(pNiebghour);
			if (heapindex != -1)//(m_OpenList.contains(pNiebghour))
			{
				//check if current path is better than old plath lower then f score
				if (currentNode->m_nFScore + nCost < pNiebghour->m_nFScore)
				{
					//update g score
					pNiebghour->m_nGScore = currentNode->m_nGScore + nCost;

					//update f score
					pNiebghour->m_nFScore = pNiebghour->m_nGScore + pNiebghour->m_nHScore;

					//update prev node pointer
					pNiebghour->m_pPrev = currentNode;
				}
				m_OpenList.Resort(heapindex);
			}
			//else (nieghbour not in open list)
			else
			{
				//calculate g score
				pNiebghour->m_nGScore = currentNode->m_nGScore + nCost;

				//calculate h score
				pNiebghour->m_nHScore = Callfunction(pNiebghour, pEnd);

				//calculate f score
				pNiebghour->m_nFScore = pNiebghour->m_nGScore + pNiebghour->m_nHScore;

				//set prev node pointer
				pNiebghour->m_pPrev = currentNode;

				//add neighbour to open list
				m_OpenList.Push(pNiebghour);

			}
		}
	}
	//no path found if we get here so return false
	return false;
}

//void AStar::SortOpenList()
//{
//	for (size_t i = 0; i < m_OpenList.Size(); ++i)
//	{
//		for (size_t j = 0; j < m_OpenList.Size() - 1; ++j)
//		{
//			if (m_OpenList[j]->m_nFScore > m_OpenList[j + 1]->m_nFScore)
//			{
//				AStarNode* swap = m_OpenList[j];
//				m_OpenList[j] = m_OpenList[j + 1];
//				m_OpenList[j + 1] = swap;
//			}
//		}
//	}
//}
