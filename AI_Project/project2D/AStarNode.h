#pragma once
#include "DynamicArray.h"

struct AStarNode;

struct AStarEdge
{
	AStarNode* m_pEndNode;
	int m_nCost;
};

struct AStarNode
{
	AStarNode(int nIndex)
	{
		m_pPrev = nullptr;
		m_nGScore = 0;
		m_nHScore = 0;
		m_nFScore = 0;
		m_nIndex = nIndex;
		m_bBlocked = false;
	}

	virtual ~AStarNode()
	{
		for (int i = 0; i < m_AdjacentList.Size(); ++i)
		{
			delete m_AdjacentList[i];
		}
	}

	AStarNode* m_pPrev;
	int m_nGScore;
	int m_nHScore;
	int m_nFScore;

	int m_nIndex;
	bool m_bBlocked;

	DynamicArray<AStarEdge*> m_AdjacentList;
};