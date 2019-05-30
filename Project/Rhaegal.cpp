#include "Rhaegal.h"



Rhaegal::Rhaegal()
{
}

Rhaegal::Rhaegal(b2World & world, int width, sf::Vector2f postion, bool circle)
	: Dragons(world, width, postion, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(5));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Rhaegal::~Rhaegal()
{
}
