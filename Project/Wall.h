#pragma once
#include "NonMoveable.h"
class Wall :
	public NonMoveable
{
public:
	Wall();
	Wall(b2World & world, int width, sf::Vector2f postion) : NonMoveable(world, width, postion) {}
	~Wall();
	virtual void coillision() = 0;
};

