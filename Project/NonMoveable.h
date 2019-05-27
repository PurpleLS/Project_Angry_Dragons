#pragma once
#include "GameObject.h"
class NonMoveable :
	public GameObject
{
public:
	NonMoveable();
	NonMoveable(b2World* world, int width, sf::Vector2f postion) : GameObject(world, width,postion){}
	~NonMoveable();
	virtual void coillision() = 0;
};

