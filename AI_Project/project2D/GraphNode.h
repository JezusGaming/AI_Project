#pragma once
#include "DynamicArray.h"

template<typename T>
class GraphNode
{
public:
	GraphNode() 
	{
		m_bTraversed = false;
	}

	GraphNode(T Data) 
	{ 
		m_Data = Data; 
		m_bTraversed = false;
	}

	~GraphNode() 
	{
	}

	void AddConnection(GraphNode<T>* other)
	{
		m_Edges.PushBack(other);
	}

	void RemoveConnection(GraphNode<T>* other)
	{
		//m_Edges.Remove(other)
		for (int i = 0; i < m_Edges.Size(); ++i)
		{
			if (m_Edges[i] == other)
			{
				m_Edges.Remove(i);
				return;
			}	
		}
	}

	bool m_bTraversed;
	DynamicArray<GraphNode<T>*> m_Edges;
	T m_Data;
};