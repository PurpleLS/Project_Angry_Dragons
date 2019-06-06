#pragma once
#include "NonMoveable.h"
class Wall :
	public NonMoveable
{
public:
	Wall();
	Wall(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize) 
		: NonMoveable(world, width, position, circle, windowSize) {}
	~Wall();
	virtual void coillision() = 0;
};

