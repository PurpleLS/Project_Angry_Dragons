#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(b2World & world, int width, sf::Vector2f position)
{
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2CircleShape circleShape;

	bodyDef.position = b2Vec2(position.x/ SCALE, position.y/ SCALE);
	bodyDef.type = b2_dynamicBody;
	m_body = world.CreateBody(&bodyDef);

	//circleShape.m_p.Set(0, 0); //position, relative to body position
	circleShape.m_radius = 10;
	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.7f;
	fixtureDef.shape = &circleShape;
	m_body->CreateFixture(&fixtureDef);

	m_sprite.setPosition(position);
	m_sprite.setScale(48 / m_sprite.getGlobalBounds().width, 48 / m_sprite.getGlobalBounds().height); // set correct scale


}

GameObject::~GameObject()
{
}

void GameObject::print(const b2Vec2 position, float32 y)
{
	m_sprite.setPosition(position.x * 100, position.y * 100);
	m_sprite.setRotation(180 / b2_pi * y);
}
