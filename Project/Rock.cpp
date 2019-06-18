#include "Rock.h"
#include "Guards.h"

Rock::Rock(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(1), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}

void Rock::updateSprite()
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(19), true);
}


void Rock::collision(GameObject & object)
{
	object.collision(*this);
}

void Rock::collision(Drogon & object)
{
	updateLife(1);
}

void Rock::collision(Viserion & object)
{
	updateLife(1);
}

void Rock::collision(Rhaegal & object)
{
	updateLife(2);
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
