#include "Ice.h"
// #include "Graphics.h"

Ice::Ice()
{
}

Ice::Ice(b2World & world, int width, sf::Vector2f postion, bool circle)
	: Wall(world, width, postion, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(2));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Ice::~Ice()
{
}

void Ice::coillision()
{
}
