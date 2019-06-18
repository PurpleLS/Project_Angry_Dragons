#include "Dragons.h"
#include <iostream>

Dragons::Dragons()
{
}

void Dragons::setActive(float x, float y)
{
	m_body->SetTransform(b2Vec2{ (x / (6 * SCALE)), (y / (1.2f*SCALE)) }, 0);
	m_body->SetType(b2_staticBody);
	m_active = true;
}

bool Dragons::checkMovement()
{
	float speedNow = m_body->GetLinearVelocity().Length();
	if (speedNow <= 0.02 && m_body->GetType() == b2_dynamicBody)
	{
		if (m_clock.getElapsedTime().asSeconds() > 2.f)
		{
			m_body->GetWorld()->DestroyBody(m_body);
			return false;
		}
	}
	else
		m_clock.restart();
	return true;
		
}

void Dragons::launchDragon()
{
	m_body->SetType(b2_dynamicBody);
	b2Vec2 vec({ (float32)((m_mousePositionStart.x - m_mousePositionEnd.x) * 25 / 100) , (float32)((m_mousePositionStart.y - m_mousePositionEnd.y) * 25 / 100)});
	m_body->SetLinearVelocity(vec);
	m_start = false;
	m_dead = true;
}

void Dragons::moveDragon(sf::Vector2f position)
{
	std::cout << "sprite x:" << m_sprite.getPosition().x << " y:" << m_sprite.getPosition().x << std::endl;
	m_body->SetTransform(b2Vec2{ (position.x)/ SCALE, (position.y) / SCALE }, 0);
	std::cout << "mouse x:" << position.x << " y:" << position.y << std::endl;
}

Dragons::~Dragons()
{
}

void Dragons::move()
{
}

void Dragons::collision(GameObject & object)
{
	object.collision(*this);
}

void Dragons::collision(Drogon & object)
{
}

void Dragons::collision(Viserion & object)
{
}

void Dragons::collision(Rhaegal & object)
{
}

void Dragons::collision(Rock & object)
{
}

void Dragons::collision(Ice & object)
{
}

void Dragons::collision(Wood & object)
{
}

void Dragons::collision(Guards & object)
{
}


