#include "Ice.h"
// #include "Graphics.h"

Ice::Ice(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(2), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}

void Ice::collision(GameObject & object)
{
}

void Ice::collision(Drogon & object)
{
}

void Ice::collision(Viserion & object)
{
}

void Ice::collision(Rhaegal & object)
{
}

void Ice::collision(Rock & object)
{
}

void Ice::collision(Ice & object)
{
}

void Ice::collision(Wood & object)
{
}

void Ice::collision(Guards & object)
{
}
