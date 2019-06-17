#include "Viserion.h"



Viserion::Viserion()
{
}

Viserion::Viserion(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Dragons(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(6));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Viserion::~Viserion()
{
}

void Viserion::collision(GameObject & object)
{
}

void Viserion::collision(Drogon & object)
{
}

void Viserion::collision(Viserion & object)
{
}

void Viserion::collision(Rhaegal & object)
{
}

void Viserion::collision(Rock & object)
{
}

void Viserion::collision(Ice & object)
{
}

void Viserion::collision(Wood & object)
{
}

void Viserion::collision(Guards & object)
{
}
