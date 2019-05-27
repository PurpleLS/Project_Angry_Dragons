#pragma once
#include "GameObject.h"
class Moveable :
	public GameObject
{
public:
	Moveable();
	~Moveable();
	Moveable(b2World* world, int width, sf::Vector2f postion) : GameObject(world, width, postion) {}
	virtual void move() = 0;

};

