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
	bool getIfStart() { return m_start; }
	void setActive(float x, float y);
	void setMousePositionStart(sf::Vector2f position) { if (!m_start) { m_mousePositionStart = position; m_start = true; } }
	void setMousePositionEnd(sf::Vector2f position) { m_mousePositionEnd = position; }
	sf::Vector2f getMousePositionStart() { return m_mousePositionStart; }
	sf::Vector2f getMousePositionEnd() { return m_mousePositionEnd; }
	void launchDragon();
	void moveDragon(sf::Vector2f position);
	~Dragons();
	virtual void move();
protected:
	bool m_active;
	bool m_start = false;
	sf::Vector2f m_mousePositionStart;
	sf::Vector2f m_mousePositionEnd;
};

