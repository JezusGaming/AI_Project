#pragma once
#include "DynamicArray.h"
#include"GraphNode.h"
#include "Stack.h"
template<typename T>
class Graph
{
public:
	Graph() {}
	~Graph() {}

	void Insert(GraphNode<T>* node)
	{
		m_Nodes.PushBack(node);
	}
	void Remove(GraphNode<T>* node)
	{

	}
	void Remove(T Data ) 
	{

	}
	void DrawGraph()
	{
		for (int i = 0; i < m_Nodes.Size(); ++i)
		{
			m_Nodes[i]->m_bTraversed = false;
		}

		Stack<GraphNode<T>*> stack;

		stack.PushBack(m_Nodes[0]);

		while (!stack.IsEmpty())
		{
			GraphNode<T>* current = stack.Pop();
			current->m_bTraversed = true;

			for (int i = 0; i < current->m_Edges.Size(); ++i)
			{
				if(!current->m_Edges[i]->m_bTraversed)
				stack.PushBack(current->m_Edges[i]);
			}
		}
	}

private:
	DynamicArray<GraphNode<T>*> m_Nodes;
};