#include "Wood.h"
#include "Guards.h"


Wood::Wood(b2World & world, int width, sf::Vector2i postion, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, postion, circle, windowSize)
{
	
	m_sprite.setTexture(* Graphics::getInstance().getTexture(0), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height);
}


void Wood::collision(GameObject & object)
{
	object.collision(*this);
}

void Wood::collision(Drogon & object)
{
	m_life -= 2;
	if (m_life <= 0)
		m_dead = true;
}

void Wood::collision(Viserion & object)
{
	m_life -= 1;
	if (m_life <= 0)
		m_dead = true;
}

void Wood::collision(Rhaegal & object)
{
	m_life -= 1;
	if (m_life <= 0)
		m_dead = true;
}

void Wood::collision(Rock & object)
{
	// nothing
}

void Wood::collision(Ice & object)
{
	// nothing
}

void Wood::collision(Wood & object)
{
	// nothing
}

void Wood::collision(Guards & object)
{
	object.collision(*this);
}
