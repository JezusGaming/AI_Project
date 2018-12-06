#pragma once
#include "Heap.h"
#include "AStarNode.h"

typedef int(*CalHeuristic)(AStarNode* , AStarNode*);

class AStar
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	AStar(int nMaxNodes);

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	~AStar();

	//----------------------------------------------------------------------------
	// calculates a path to follow which is the cheapest to move
	//
	// Param:
	//      pStart: pointer to AStarNode which is the start of the path 
	//		pEnd: pointer to AStarNode which is the end of the path 
	//		finishedPath: is a dynamicArray of the finished path using AStarNodes
	//----------------------------------------------------------------------------
	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, DynamicArray<AStarNode*>* finishedPath);
	//pointer func
	int Callfunction(AStarNode* pNode, AStarNode* pEnd);
	void SetFunction(CalHeuristic func);

private:
	//void SortOpenList(); //wont need this if you have a heap

	Heap m_OpenList; 
	bool* m_ClosedList;
	int m_nMaxNodes;
	CalHeuristic calHeuristic = nullptr;
};

