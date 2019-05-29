#include "Ice.h"
// #include "Graphics.h"

Ice::Ice()
{
}

Ice::Ice(b2World & world, int width, sf::Vector2f postion)
	: Wall(world, width, postion)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(2));
}


Ice::~Ice()
{
}

void Ice::coillision()
{
}
