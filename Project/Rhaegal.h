#pragma once
#include "Dragons.h"
class Rhaegal :
	public Dragons
{
public:
	Rhaegal();
	Rhaegal(b2World & world, int width, sf::Vector2f postion);
	~Rhaegal();
};

