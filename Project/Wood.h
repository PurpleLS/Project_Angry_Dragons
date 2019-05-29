#pragma once
#include "Wall.h"
class Wood :
	public Wall
{
public:
	Wood();
	Wood(b2World & world, int width, sf::Vector2f postion);
	~Wood();
	virtual void coillision();
};

