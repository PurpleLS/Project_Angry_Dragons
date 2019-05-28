#include "Wood.h"



Wood::Wood()
{
}

Wood::Wood(b2World * world, int width, sf::Vector2f postion)
	: Wall(world, width, postion)
{
	m_sprite.setTexture(* Graphics::getInstance().getTexture(0));
}


Wood::~Wood()
{
}

void Wood::coillision()
{
}
