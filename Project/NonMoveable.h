#pragma once
#include "GameObject.h"
class NonMoveable :
	public GameObject
{
public:
	NonMoveable();
	~NonMoveable();
	virtual void coillision() = 0;
};

