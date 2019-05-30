#pragma once
#include "Wall.h"

class Ice :
	public Wall
{
public:
	Ice(b2World & world, int width, sf::Vector2i postion, bool circle);
	virtual void coillision();
};

