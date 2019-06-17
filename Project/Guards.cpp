#include "Guards.h"



Guards::Guards()
{
}

Guards::Guards(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: NonMoveable(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(3), true);
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Guards::~Guards()
{
}


void Guards::collision(GameObject & object)
{
}

void Guards::collision(Drogon & object)
{
}

void Guards::collision(Viserion & object)
{
}

void Guards::collision(Rhaegal & object)
{
}

void Guards::collision(Rock & object)
{
}

void Guards::collision(Ice & object)
{
}

void Guards::collision(Wood & object)
{
}

void Guards::collision(Guards & object)
{
}
