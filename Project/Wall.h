#pragma once
#include "NonMoveable.h"
class Wall :
	public NonMoveable
{
public:
	Wall();
	Wall(b2World & world, int width, sf::Vector2i postion, bool circle) : NonMoveable(world, width, postion, circle) {}
	~Wall();
	virtual void coillision() = 0;
};

