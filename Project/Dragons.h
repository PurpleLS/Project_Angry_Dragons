#pragma once
#include "Moveable.h"
class Dragons :
	public Moveable
{
public:
	Dragons();
	Dragons(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize) 
		: Moveable(world, width, position, circle, windowSize) {}
	~Dragons();
	virtual void move();
};

