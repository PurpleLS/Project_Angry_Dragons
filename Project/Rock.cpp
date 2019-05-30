#include "Rock.h"

Rock::Rock(b2World & world, int width, sf::Vector2i postion, bool circle)
	: Wall(world, width, postion, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(1));
	m_sprite.setScale((50.f* width) / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}

void Rock::coillision()
{
}
