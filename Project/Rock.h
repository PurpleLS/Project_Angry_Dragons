#pragma once
#include "Wall.h"
class Rock :
	public Wall
{
public:
	Rock();
	Rock(b2World* world, int width, sf::Vector2f postion) : Wall(world, width, postion) {}
	~Rock();
	virtual void coillision();
};

