#pragma once
#include "Moveable.h"
class Dragons :
	public Moveable
{
public:
	Dragons();
	Dragons(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize) 
		: Moveable(world, width, position, circle, windowSize) { m_type = 1;  m_active = false; }
	bool getActive() { return m_active; }
	void setActive() { m_active = true; }
	~Dragons();
	virtual void move();
protected:
	bool m_active;
};

