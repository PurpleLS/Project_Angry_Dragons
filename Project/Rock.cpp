#include "Rock.h"

Rock::Rock(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(1), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


void Rock::collision(GameObject & object)
{
}

void Rock::collision(Drogon & object)
{
}

void Rock::collision(Viserion & object)
{
}

void Rock::collision(Rhaegal & object)
{
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
}
