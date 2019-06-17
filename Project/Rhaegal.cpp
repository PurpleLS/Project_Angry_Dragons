#include "Rhaegal.h"



Rhaegal::Rhaegal()
{
}

Rhaegal::Rhaegal(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Dragons(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(5));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Rhaegal::~Rhaegal()
{
}

void Rhaegal::collision(GameObject & object)
{
}

void Rhaegal::collision(Drogon & object)
{
}

void Rhaegal::collision(Viserion & object)
{
}

void Rhaegal::collision(Rhaegal & object)
{
}

void Rhaegal::collision(Rock & object)
{
}

void Rhaegal::collision(Ice & object)
{
}

void Rhaegal::collision(Wood & object)
{
}

void Rhaegal::collision(Guards & object)
{
}
