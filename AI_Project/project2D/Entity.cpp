#include "Entity.h"



Entity::Entity()
{
	m_bActive = false;
}


Entity::~Entity()
{
}

void Entity::setActive(bool bActive)
{
	m_bActive = bActive;
}

bool Entity::getActive()
{
	return m_bActive;
}
