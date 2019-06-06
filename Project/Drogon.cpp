#include "Drogon.h"

Drogon::Drogon(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Dragons(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(4));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}
