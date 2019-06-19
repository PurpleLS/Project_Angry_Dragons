#include "Wall.h"

Wall ::Wall()
{
}


Wall::~Wall()
{
}

void Wall::collision(GameObject & object)
{
	object.collision(*this);
}

void Wall::collision(Drogon & object)
{
}

void Wall::collision(Viserion & object)
{
}

void Wall::collision(Rhaegal & object)
{
}

void Wall::collision(Rock & object)
{
}

void Wall::collision(Ice & object)
{
}

void Wall::collision(Wood & object)
{
}

void Wall::collision(Guards & object)
{
}

