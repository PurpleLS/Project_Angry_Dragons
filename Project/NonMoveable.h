#pragma once
#include "GameObject.h"
class NonMoveable :
	public GameObject
{
public:
	NonMoveable();
	NonMoveable(b2World & world, int width, sf::Vector2f postion, bool circle) : GameObject(world, width,postion, circle){}
	~NonMoveable();
	virtual void coillision() = 0;
};

