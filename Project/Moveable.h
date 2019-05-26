#pragma once
#include "GameObject.h"
class Moveable :
	public GameObject
{
public:
	Moveable();
	~Moveable();
	virtual void move() = 0;

};

