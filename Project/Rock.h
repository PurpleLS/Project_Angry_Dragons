#pragma once
#include "Wall.h"
class Rock :
	public Wall
{
public:
	Rock();
	~Rock();
	virtual void coillision();
};

