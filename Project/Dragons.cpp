#include "Dragons.h"



Dragons::Dragons()
{
}

void Dragons::setActive(float x, float y)
{
	m_body->SetTransform(b2Vec2{ (x / (6 * SCALE)), (y / (1.2f*SCALE)) }, 0);
	m_body->SetType(b2_staticBody);
	m_active = true;
}

void Dragons::launchDragon()
{
	m_body->SetType(b2_dynamicBody);
	b2Vec2 vec({ (float32)((m_mousePositionStart.x - m_mousePositionEnd.x)* 5 / 10) , (float32)((m_mousePositionStart.y - m_mousePositionEnd.y) * 5 / 10)});
	m_body->SetLinearVelocity(vec);
	// m_active = false; // ????????????????
}

void Dragons::moveDragon(sf::Vector2f position)
{
	m_body->SetTransform(b2Vec2{ (position.x)/ SCALE, (position.y) / SCALE }, 0);
}

Dragons::~Dragons()
{
}

void Dragons::move()
{
}
