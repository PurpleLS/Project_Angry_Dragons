#include "Rock.h"
#include "Guards.h"

Rock::Rock(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(1), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


void Rock::collision(GameObject & object)
{
	object.collision(*this);
}

void Rock::collision(Drogon & object)
{
	m_life -= 1;
	if (m_life <= 0)
		m_dead = true;
}

void Rock::collision(Viserion & object)
{
	m_life -= 1;
	if (m_life <= 0)
		m_dead = true;
}

void Rock::collision(Rhaegal & object)
{
	m_life -= 2;
	if (m_life <= 0)
		m_dead = true;
}

void Rock::collision(Rock & object)
{
}

void Rock::collision(Ice & object)
{
}

void Rock::collision(Wood & object)
{
}

void Rock::collision(Guards & object)
{
	object.collision(*this);
}
