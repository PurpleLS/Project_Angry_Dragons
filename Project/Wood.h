#pragma once
#include "Wall.h"
class Wood :
	public Wall
{
public:
	Wood(b2World & world, int width, sf::Vector2i postion, bool circle);
	virtual void coillision();
};

