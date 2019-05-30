#pragma once
#include "Wall.h"
class Rock :
	public Wall
{
public:
	Rock(b2World & world, int width, sf::Vector2f postion, bool circle);
	void coillision() override;
};

