#include "Rock.h"

Rock::Rock(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Wall(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(1), true);
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}

void Rock::coillision()
{
}
