#include "Rhaegal.h"



Rhaegal::Rhaegal()
{
}

Rhaegal::Rhaegal(b2World & world, int width, sf::Vector2f postion)
	: Dragons(world, width, postion)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(5));
}


Rhaegal::~Rhaegal()
{
}
