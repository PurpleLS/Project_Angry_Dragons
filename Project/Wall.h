#pragma once
#include "NonMoveable.h"
class Wall :
	public NonMoveable
{
public:
	Wall();
	~Wall();\
	virtual void collision();
};

