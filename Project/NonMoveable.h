#pragma once
#include "GameObject.h"
class NonMoveable :
	public GameObject
{
public:
	NonMoveable();
	NonMoveable(b2World & world, int width, sf::Vector2i position, bool circle) : GameObject(world, width,position, circle){}
	~NonMoveable();
	virtual void coillision() = 0;
};

