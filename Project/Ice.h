#pragma once
#include "Wall.h"

class Ice :
	public Wall
{
public:
	Ice();
	Ice(b2World & world, int width, sf::Vector2f postion, bool circle);
	~Ice();
	virtual void coillision();
};

