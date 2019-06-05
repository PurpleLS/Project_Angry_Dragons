#pragma once
#include "NonMoveable.h"
class Guards :
	public NonMoveable
{
public:
	Guards();
	Guards(b2World & world, int width, sf::Vector2i position, bool circle);
	~Guards();
	virtual void coillision();
};

