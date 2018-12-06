#pragma once
#include "LinkedList.h"

template<typename T>
class Queue
{
public:
	Queue(int initailSize)
	{
		Q = new LinkedList<T>[initailSize];
	}
	~Queue()
	{
		delete Q;
	}

	void Push(T value)
	{
		Q.PushBack(value);
	}

	T Pop()
	{
		Q.popFront(value);
	}

	T Top()
	{
		return Q.Last();
	}

	bool Empty()
	{
		return (Q.Size() == 0)
	}

	int size()
	{
		return Q.Size();
	}
private:
	LinkedList<T> Q;
};

