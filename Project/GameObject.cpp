#include "GameObject.h"


GameObject::GameObject()
{

}

GameObject::GameObject(b2World & world, int width, sf::Vector2i vi, bool circle, sf::Vector2u windowSize)
{
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2CircleShape circleShape;
	b2PolygonShape boxShape;
	m_width = width;
	bodyDef.userData = this;
	bodyDef.position = b2Vec2((windowSize.x / (2*SCALE)) + (vi.x)*(50 / SCALE) + 5,
							  (windowSize.y/SCALE) - 2.6 - (vi.y - 1)*(50 / SCALE) );
	bodyDef.type = b2_dynamicBody; /* b2_staticBody; b2_dynamicBody */ 
	m_body = world.CreateBody(&bodyDef);

	if (circle)
	{
		circleShape.m_radius = (50.f / 2) / SCALE;
		circleShape.m_p.Set((50.f*width) / (2 * SCALE), (50.f) / (2 * SCALE));
	}	
	else
		boxShape.SetAsBox(((50.f / 2)*(width)) / SCALE, (50.f / 2) / SCALE,
			b2Vec2{ (50.f*width) / (2 * SCALE), (50.f) / (2 * SCALE) }, 0) ;
	// boxShape.SetAsBox()

	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.7f;

	if (circle)
		fixtureDef.shape = &circleShape;
	else
		fixtureDef.shape = &boxShape;

	//circleShape.m_p.Set(0, 0); //position, relative to body position
	// Shape.m_radius = 10;

	m_body->CreateFixture(&fixtureDef);

}

GameObject::~GameObject()
{
}

/* void GameObject::print(const b2Vec2 position, float32 y)
{
	
	auto location = sf::Vector2f{ position.x , position.y } * SCALE;
	m_sprite.setPosition(location);
	m_sprite.setRotation(180 / b2_pi * y);
} */

void GameObject::print(sf::RenderWindow & window)
{
	m_sprite.setPosition(m_body->GetPosition().x *SCALE, m_body->GetPosition().y *SCALE);
	m_sprite.setRotation(m_body->GetAngle() * 180 / b2_pi);
	window.draw(m_sprite);
}

