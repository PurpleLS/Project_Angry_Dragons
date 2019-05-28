#pragma once
#include "Dragons.h"
class Drogon :
	public Dragons
{
public:
	Drogon();
	Drogon(b2World* world, int width, sf::Vector2f postion);
	~Drogon();
};

