#pragma once
#include "GameObject.h"
class Moveable :
	public GameObject
{
public:
	Moveable();
	~Moveable();
	Moveable(b2World & world, int width, sf::Vector2i postion, bool circle) : GameObject(world, width, postion, circle) {}
	virtual void move() = 0;

};

