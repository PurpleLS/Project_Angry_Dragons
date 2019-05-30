#pragma once
#include "Moveable.h"
class Dragons :
	public Moveable
{
public:
	Dragons();
	Dragons(b2World & world, int width, sf::Vector2f postion, bool circle) : Moveable(world, width, postion, circle) {}
	~Dragons();
	virtual void move();
};

