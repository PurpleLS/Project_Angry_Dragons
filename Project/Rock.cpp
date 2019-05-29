#include "Rock.h"



Rock::Rock()
{
}

Rock::Rock(b2World & world, int width, sf::Vector2f postion)
	: Wall(world, width, postion)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(1));
}


Rock::~Rock()
{
}

void Rock::coillision()
{
}
