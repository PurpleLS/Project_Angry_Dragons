#include "Wood.h"
#include "Guards.h"


Wood::Wood(b2World & world, int width, sf::Vector2i postion, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, postion, circle, windowSize)
{
	
	m_sprite.setTexture(* Graphics::getInstance().getTexture(0), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height);
}

void Wood::updateSprite()
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(20), true);
}


void Wood::collision(GameObject & object)
{
	object.collision(*this);
}

void Wood::collision(Drogon & object)
{
	updateLife(2);
}

void Wood::collision(Viserion & object)
{
	updateLife(1);
}

void Wood::collision(Rhaegal & object)
{
	updateLife(1);
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
