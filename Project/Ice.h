#pragma once
#include "Wall.h"

class Ice :
	public Wall
{
public:
	Ice(b2World & world, int width, sf::Vector2i position, bool circle);
	virtual void coillision();
};

