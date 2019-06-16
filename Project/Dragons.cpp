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
	if (speedNow <= 0.02)
		if (m_clock.getElapsedTime().asSeconds() > 3.f)
			return false;
	return true;
		
}

void Dragons::launchDragon()
{
	m_body->SetType(b2_dynamicBody);
	b2Vec2 vec({ (float32)((m_mousePositionStart.x - m_mousePositionEnd.x) * 25 / 100) , (float32)((m_mousePositionStart.y - m_mousePositionEnd.y) * 25 / 100)});
	m_body->SetLinearVelocity(vec);
	m_start = false;
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
