#include "Viserion.h"



Viserion::Viserion()
{
}

Viserion::Viserion(b2World & world, int width, sf::Vector2f postion, bool circle)
	: Dragons(world, width, postion, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(6));
}


Viserion::~Viserion()
{
}
