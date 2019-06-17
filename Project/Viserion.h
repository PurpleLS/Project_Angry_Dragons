#pragma once
#include "Dragons.h"
class Viserion :
	public Dragons
{
public:
	Viserion();
	Viserion(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize);
	~Viserion();

	// Inherited via Dragons
	virtual void collision(GameObject & object) override;
	virtual void collision(Drogon & object) override;
	virtual void collision(Viserion & object) override;
	virtual void collision(Rhaegal & object) override;
	virtual void collision(Rock & object) override;
	virtual void collision(Ice & object) override;
	virtual void collision(Wood & object) override;
	virtual void collision(Guards & object) override;
};

