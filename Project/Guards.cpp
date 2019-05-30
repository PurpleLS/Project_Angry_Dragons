#include "Guards.h"



Guards::Guards()
{
}

Guards::Guards(b2World & world, int width, sf::Vector2f postion, bool circle)
	: NonMoveable(world, width, postion, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(3));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Guards::~Guards()
{
}

void Guards::coillision()
{
}
