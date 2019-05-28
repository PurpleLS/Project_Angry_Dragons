#pragma once
#include "Moveable.h"
class Dragons :
	public Moveable
{
public:
	Dragons();
	Dragons(b2World* world, int width, sf::Vector2f postion) : Moveable(world, width, postion) {}
	~Dragons();
	virtual void move();
};

