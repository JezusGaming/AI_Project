#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	void setActive(bool bActive);
	bool getActive();

private:
	bool m_bActive;
};

