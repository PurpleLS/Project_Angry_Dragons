#include "NonMoveable.h"
#include "Guards.h"
#include "Wall.h"


NonMoveable::NonMoveable()
{
}


NonMoveable::~NonMoveable()
{
}

void NonMoveable::updateLife(int i)
{
	m_life -= i;
	if (m_life <= 0)
		m_dead = true;
	if (m_life < 3)
		updateSprite();
}

void NonMoveable::collision(GameObject & object)
{
	object.collision(*this);
}

void NonMoveable::collision(Drogon & object)
{
}

void NonMoveable::collision(Viserion & object)
{
}

void NonMoveable::collision(Rhaegal & object)
{
}

void NonMoveable::collision(Rock & object)
{
}

void NonMoveable::collision(Ice & object)
{
}

void NonMoveable::collision(Wood & object)
{
}

void NonMoveable::collision(Guards & object)
{
}

