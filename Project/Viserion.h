#pragma once
#include "Dragons.h"
class Viserion :
	public Dragons
{
public:
	Viserion();
	Viserion(b2World & world, int width, sf::Vector2i postion, bool circle);
	~Viserion();
};

