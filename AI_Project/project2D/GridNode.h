#pragma once
#include "Astarnode.h"
#include "Vector2.h"

struct GridNode : public AStarNode
{
	GridNode(Vector2 pos, int nIndex, int nIndexX, int nIndexY) : AStarNode(nIndex)
	{
		m_v2Pos = pos;
		m_nIndexX = nIndexX;
		m_nIndexY = nIndexY;
	}

	int m_nIndexX;
	int m_nIndexY;

	Vector2 m_v2Pos;
};