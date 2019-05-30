#include "Guards.h"



Guards::Guards()
{
}

Guards::Guards(b2World & world, int width, sf::Vector2f postion, bool circle)
	: NonMoveable(world, width, postion, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(3));
}


Guards::~Guards()
{
}

void Guards::coillision()
{
}
