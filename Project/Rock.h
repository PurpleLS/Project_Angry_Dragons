#pragma once
#include "Wall.h"
class Rock :
	public Wall
{
public:
	Rock(b2World & world, int width, sf::Vector2i position, bool circle);
	void coillision() override;
};

