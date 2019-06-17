#pragma once
#include "GameObject.h"

class NonMoveable :
	public GameObject
{
public:
	NonMoveable();
	NonMoveable(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize) 
		: GameObject(world, width,position, circle, windowSize){}
	~NonMoveable();

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
	float m_life = 3;
};

