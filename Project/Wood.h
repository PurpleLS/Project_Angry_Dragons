#pragma once
#include "Wall.h"
class Wood :
	public Wall
{
public:
	Wood(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize);
	virtual void coillision();
};

