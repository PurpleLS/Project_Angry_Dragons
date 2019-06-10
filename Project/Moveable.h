#pragma once
#include "GameObject.h"
class Moveable :
	public GameObject
{
public:
	Moveable();
	~Moveable();
	Moveable(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize) 
		: GameObject(world, width, position, circle, windowSize) {}
	virtual void move() = 0;
	

};

