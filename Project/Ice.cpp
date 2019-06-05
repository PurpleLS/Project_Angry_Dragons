#include "Ice.h"
// #include "Graphics.h"

Ice::Ice(b2World & world, int width, sf::Vector2i position, bool circle)
	: Wall(world, width, position, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(2), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}

void Ice::coillision()
{
}
