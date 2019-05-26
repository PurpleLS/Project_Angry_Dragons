#pragma once
#include "Wall.h"
class Wood :
	public Wall
{
public:
	Wood();
	~Wood();
	virtual void coillision();
};

