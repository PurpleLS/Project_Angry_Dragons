#include "NonMoveable.h"
#include "Guards.h"
#include "Wall.h"


NonMoveable::NonMoveable()
{
}


NonMoveable::~NonMoveable()
{
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

