#include "Viserion.h"
#include "Rhaegal.h"
#include "Drogon.h"
#include "Rock.h"
#include "Wood.h"
#include "Guards.h"
#include "Ice.h"



Viserion::Viserion()
{
}

Viserion::Viserion(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Dragons(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(6));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Viserion::~Viserion()
{
}

void Viserion::collision(GameObject & object)
{
	object.collision(*this);
}

void Viserion::collision(Drogon & object)
{
	//--------------
}

void Viserion::collision(Viserion & object)
{
	//----------------
}

void Viserion::collision(Rhaegal & object)
{
	//------------------
}

void Viserion::collision(Rock & object)
{
	object.collision(*this);
}

void Viserion::collision(Ice & object)
{
	object.collision(*this);
}

void Viserion::collision(Wood & object)
{
	object.collision(*this);
}

void Viserion::collision(Guards & object)
{
	object.collision(*this);
}
