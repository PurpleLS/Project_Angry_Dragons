#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(b2World & world, int width, sf::Vector2i vi, bool circle)
{
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2CircleShape circleShape;
	b2PolygonShape boxShape;
	m_width = width;
	// sf::Vector2i i = mapCoordsToPixel(position);
	bodyDef.userData = this;
	bodyDef.position = b2Vec2((960 + (vi.x + (width-0.5)/2)*50)  / SCALE, (200 + vi.y*50) / SCALE);
	bodyDef.type = b2_dynamicBody; // b2_staticBody; 
	m_body = world.CreateBody(&bodyDef);

	/*if (circle)
		circleShape.m_radius = 30;
	else*/
	boxShape.SetAsBox(((50.f / 2)*width) / SCALE, (50.f / 2) / SCALE);

	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.7f;

	//if (circle)
	//	fixtureDef.shape = &circleShape;
	//else
	fixtureDef.shape = &boxShape;

	m_body->CreateFixture(&fixtureDef);

	//m_sprite.setOrigin(25.f * m_width, 25.f);
	//circleShape.m_p.Set(0, 0); //position, relative to body position
	// Shape.m_radius = 10;

	//if (circle)
	//	fixtureDef.shape = &circleShape;
	//else
	//	fixtureDef.shape = &boxShape;

	//m_body->CreateFixture(&fixtureDef);
	//m_sprite.setPosition(position);

}

GameObject::~GameObject()
{
}
#include <iostream>
void GameObject::print(const b2Vec2 position, float32 y)
{
	// 	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	m_sprite.setPosition((position.x * SCALE) -(25 * m_width) , (position.y * SCALE) - 25);
	std::cout << position.x * SCALE << " " << position.y * SCALE << "\n";
	std::cout << m_sprite.getPosition().x << " " << m_sprite.getPosition().y << "\n";
	// m_sprite.setPosition((position.x * SCALE)-(m_width/2)* 50.f , position.y * SCALE);
	//m_sprite.setOrigin(position.x * SCALE, position.y * SCALE);
	 m_sprite.setRotation(180 / b2_pi * y);
}
