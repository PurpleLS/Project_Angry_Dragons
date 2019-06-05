#pragma once
#include "Wall.h"
class Wood :
	public Wall
{
public:
	Wood(b2World & world, int width, sf::Vector2i position, bool circle);
	virtual void coillision();
};

