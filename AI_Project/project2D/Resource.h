#pragma once
#include <string.h>

template<typename T>
class Resource
{
public:
	Resource(char* szFileName)
	{
		int length = strlen(szFileName) + 1;
		_ASSERT(m_szFileName);
		m_szFileName = new char[length];
		strcpy_s(m_szFileName, length, szFileName);

		m_pData = new T(szFileName);
	}

	~Resource()
	{
		delete m_pData;
		delete[] m_szFileName;
	}

	char* m_szFileName;
	T* m_pData;
};