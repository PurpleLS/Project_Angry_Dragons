#pragma once
#include "Wall.h"
class Wood :
	public Wall
{
public:
	Wood();
	Wood(b2World & world, int width, sf::Vector2f postion, bool circle);
	~Wood();
	virtual void coillision();
};

