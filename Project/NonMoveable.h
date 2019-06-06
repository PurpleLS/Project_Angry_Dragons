#pragma once
#include "GameObject.h"
class NonMoveable :
	public GameObject
{
public:
	NonMoveable();
	NonMoveable(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize) 
		: GameObject(world, width,position, circle, windowSize){}
	~NonMoveable();
	virtual void coillision() = 0;
};

