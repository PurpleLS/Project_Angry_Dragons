#include "Guards.h"
#include "Rock.h"
#include "Ice.h"
#include "Wood.h"



Guards::Guards()
{
}

Guards::Guards(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize)
	: NonMoveable(world, width, position, circle, windowSize)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(3));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Guards::~Guards()
{
}

// Check if the guard is above or below 
bool Guards::checkAbove(float gY, float wY)
{
	if (gY >= wY)
		return false;
	return true;
}


void Guards::collision(GameObject & object)
{
	object.collision(*this);
}

void Guards::collision(Drogon & object)
{
	m_life -= 2;
	if (m_life <= 0)
		m_dead = true;
}

void Guards::collision(Viserion & object)
{
	m_life -= 2;
	if (m_life <= 0)
		m_dead = true;
}

void Guards::collision(Rhaegal & object)
{
	m_life -= 2;
	if (m_life <= 0)
		m_dead = true;
}

void Guards::collision(Rock & object)
{
	if (checkAbove(m_body->GetPosition().y, object.getBody()->GetPosition().y))
	{
		m_life -= 1;
		if (m_life <= 0)
			m_dead = true;
	}
}

void Guards::collision(Ice & object)
{
	if (checkAbove(m_body->GetPosition().y, object.getBody()->GetPosition().y))
	{
		m_life -= 1;
		if (m_life <= 0)
			m_dead = true;
	}
}

void Guards::collision(Wood & object)
{
	if (checkAbove(m_body->GetPosition().y, object.getBody()->GetPosition().y))
	{
		m_life -= 1;
		if (m_life <= 0)
			m_dead = true;
	}
}

void Guards::collision(Guards & object)
{
	//
}
