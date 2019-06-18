#include "Ice.h"
#include <iostream>
#include "Guards.h"


Ice::Ice(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(2), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}

void Ice::updateSprite()
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(18), true);
}

void Ice::collision(GameObject & object)
{
	object.collision(*this);
}

void Ice::collision(Drogon & object)
{
	updateLife(1);
}

void Ice::collision(Viserion & object)
{
	updateLife(2);
}

void Ice::collision(Rhaegal & object)
{
	updateLife(1);
}

void Ice::collision(Rock & object)
{
	// nothing 
}

void Ice::collision(Ice & object)
{
	// nothing 
}

void Ice::collision(Wood & object)
{
	// nothing 
}

void Ice::collision(Guards & object)
{
	object.collision(*this);
}
