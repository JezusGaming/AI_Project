#pragma once
#include "DynamicArray.h"
#include <math.h>
#include "AStarNode.h"

class Heap
{
public:
	Heap()
	{
	}
	~Heap()
	{
	}

	void Push(AStarNode* data)
	{
		//add data to end of array 
		m_Data.PushBack(data);

		//loop through and swap data with parent if data is smaller
		int current = m_Data.Size() - 1;
		while (true)
		{
			if (current == 0)
				break;

			int parent = GetParentIndex(current);

			if (m_Data[current]->m_nFScore < m_Data[parent]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[parent];
				m_Data[parent] = swap;

				current = parent;
			}
			else
			{
				break;
			}
		}

		//repeat until no more swaps required
	}

	AStarNode* Pop()
	{
		AStarNode* result = m_Data[0];
		//replace first element with last element
		int last = m_Data.Size() - 1;
		m_Data[0] = m_Data[last];

		int current = 0;

		while (true)
		{
			int child0 = GetChildIndex(current, 1);
			if (child0 > last)
				break;

			int child1 = GetChildIndex(current, 2);
			int smallerChild = child0;
			if (child1 <= last && m_Data[child1]->m_nFScore < m_Data[smallerChild]->m_nFScore)
				smallerChild = child1;
		//swap first element with smaller child if child is smaller
			if (m_Data[smallerChild]->m_nFScore < m_Data[current]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[smallerChild];
				m_Data[smallerChild] = swap;

				current = smallerChild;
			}
			else
			{
				break;
			}
				
		}

		m_Data.PopBack();
		return result;
		
		//repeat
	}

	void Clear()
	{
		m_Data.Clear();
	}

	int GetSize()
	{
		return (int)m_Data.Size();
	}

	int GetParentIndex(int ChildIndex)
	{
		return (ChildIndex - 1) / 2;
	}

	int GetChildIndex(int parentIndex, int whichChild)
	{
		return (2 * parentIndex) + whichChild;
	}

	int contains(AStarNode* pData)
	{
		for (int i = 0; i < m_Data.Size(); ++i)
		{
			if (m_Data[i] == pData)
				return i;
		}
		return -1;
	}

	void Resort(int Index)
	{
		if (Index == 0)
			return;

		int nNodeIndex = Index;
		int nParent = GetParentIndex(Index);

		while (nParent >= 0 && m_Data[nNodeIndex]->m_nFScore < m_Data[nParent]->m_nFScore)
		{
			AStarNode* temp = m_Data[nParent];
			m_Data[nParent] = m_Data[nNodeIndex];
			m_Data[nNodeIndex] = temp;

			nNodeIndex = nParent;
			nParent = GetParentIndex(nNodeIndex);
		}
	}

private:
	DynamicArray<AStarNode*> m_Data;
};