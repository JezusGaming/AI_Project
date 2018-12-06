#include "ObjectPool.h"
#include "Entity.h"
#include <crtdbg.h>

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	_ASSERT(m_pPool);
	m_pPool = new Entity*[nMaxSize];
	for (int i = 0; i < nMaxSize; ++i)
	{
		_ASSERT(m_pPool[i]);
		m_pPool[i] = new Entity();
	}
}
ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}
	delete[] m_pPool;
}

Entity* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pPool[i]->getActive())
		{
			m_pPool[i]->setActive(true);
			return m_pPool[i];
		}
	}
	return nullptr;
}

void ObjectPool::Deallocate(Entity * object)
{
	object->setActive(false);
}
