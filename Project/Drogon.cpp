#include "Viserion.h"
#include "Rhaegal.h"
#include "Drogon.h"
#include "Rock.h"
#include "Wood.h"
#include "Guards.h"
#include "Ice.h"


Drogon::Drogon(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: Dragons(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(4));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}

void Drogon::collision(GameObject & object)
{
	object.collision(*this);
}

void Drogon::collision(Drogon & object)
{
	// ------
}

void Drogon::collision(Viserion & object)
{
	//-------
}

void Drogon::collision(Rhaegal & object)
{
	//-------
}

void Drogon::collision(Rock & object)
{
	object.collision(*this);
}

void Drogon::collision(Ice & object)
{
	object.collision(*this);
}

void Drogon::collision(Wood & object)
{
	object.collision(*this);
}

void Drogon::collision(Guards & object)
{
	object.collision(*this);
}
