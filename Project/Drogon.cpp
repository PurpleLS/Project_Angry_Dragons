#include "Drogon.h"



Drogon::Drogon()
{
}

Drogon::Drogon(b2World & world, int width, sf::Vector2f postion)
	: Dragons(world, width, postion)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(4));
}


Drogon::~Drogon()
{
}
