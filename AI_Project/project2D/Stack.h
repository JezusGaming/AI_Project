#pragma once
#include "DynamicArray.h"

template<typename T>
class Stack
{
public:
	Stack(int initialSize = 0)
	{
		//m_pData = new DynamicArray<T>(initialSize);
	}

	~Stack()
	{
		//delete m_pData;
	}

	bool IsEmpty()
	{
		return (m_pData.Size() == 0);
	}

	int Size()
	{
		return m_pData.Size();
	}

	void PushBack(T Value)
	{
		m_pData.PushBack(Value);
	}

	T Pop()
	{
		return m_pData.PopBack();
	}

	T Top()
	{
		int nTop = m_pData.Size() - 1;
		return m_pData[nTop];
	}

	T& operator[] (const int index)
	{
		return m_pData[index];
	}
	
private:
	DynamicArray<T> m_pData;
};