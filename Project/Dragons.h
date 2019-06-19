#pragma once
#include "GameObject.h"

class Dragons :
	public GameObject
{
public:
	Dragons();
	Dragons(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize) 
		: GameObject(world, width, position, circle, windowSize) { m_active = false; m_body->SetType(b2_staticBody);}
	bool getActive() { return m_active; }
	bool getIfStart() { return m_start; }
	// bool getIfUsed() { return m_used; }
	void setActive(float x, float y);
	void setMousePositionStart(sf::Vector2f position) { if (!m_start) { m_mousePositionStart = position; m_start = true; } }
	// void setMousePositionEnd(sf::Vector2f position) { m_mousePositionEnd = position; }
	sf::Vector2f getMousePositionStart() { return m_mousePositionStart; }
	// sf::Vector2f getMousePositionEnd() { return m_mousePositionEnd; }
	bool checkMovement();
	void launchDragon();
	void moveDragon(sf::Vector2f position, sf::RenderWindow & window);
	~Dragons();
	virtual void move();

	// Inherited via GameObject
	virtual void collision(GameObject & object) override;
	virtual void collision(Drogon & object) override;
	virtual void collision(Viserion & object) override;
	virtual void collision(Rhaegal & object) override;
	virtual void collision(Rock & object) override;
	virtual void collision(Ice & object) override;
	virtual void collision(Wood & object) override;
	virtual void collision(Guards & object) override;

protected:
	bool m_active;
	bool m_start = false;
	// bool m_used = false;
	sf::Vector2f m_mousePositionStart;
	// sf::Vector2f m_mousePositionEnd;
	sf::Clock m_clock;

};

