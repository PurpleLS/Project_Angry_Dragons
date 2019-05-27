#pragma once
#include "Wall.h"
#include "Graphics.h"
class Ice :
	public Wall
{
public:
	Ice();
	Ice(b2World* world, int width, sf::Vector2f postion);
	~Ice();
	virtual void coillision();
};

