#include "Viserion.h"



Viserion::Viserion()
{
}

Viserion::Viserion(b2World & world, int width, sf::Vector2f postion)
	: Dragons(world, width, postion)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(6));
}


Viserion::~Viserion()
{
}
