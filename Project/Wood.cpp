#include "Wood.h"


Wood::Wood(b2World & world, int width, sf::Vector2i postion, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, postion, circle, windowSize)
{
	
	m_sprite.setTexture(* Graphics::getInstance().getTexture(0), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height);
}


void Wood::collision(GameObject & object)
{
}

void Wood::collision(Drogon & object)
{
}

void Wood::collision(Viserion & object)
{
}

void Wood::collision(Rhaegal & object)
{
}

void Wood::collision(Rock & object)
{
}

void Wood::collision(Ice & object)
{
}

void Wood::collision(Wood & object)
{
}

void Wood::collision(Guards & object)
{
}
