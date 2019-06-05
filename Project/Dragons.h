#pragma once
#include "Moveable.h"
class Dragons :
	public Moveable
{
public:
	Dragons();
	Dragons(b2World & world, int width, sf::Vector2i position, bool circle) : Moveable(world, width, position, circle) {}
	~Dragons();
	virtual void move();
};

