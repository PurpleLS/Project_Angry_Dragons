#include "GameObject.h"


#include "Dragons.h"
#include "Viserion.h" 
#include "Rhaegal.h" 
#include "NonMoveable.h" 
#include "Wall.h" 
#include "Wood.h"
#include "Ice.h"
#include "Rock.h"
#include "Guards.h"

GameObject::GameObject()
{

}

GameObject::GameObject(b2World & world, int width, sf::Vector2i vi, bool circle, sf::Vector2u windowSize)
{
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2CircleShape circleShape;
	b2PolygonShape octagonShape;
	b2PolygonShape boxShape;
	m_width = width;
	bodyDef.userData = this;
	bodyDef.position = b2Vec2((windowSize.x / (2*SCALE)) + (vi.x)*(50 / SCALE) + 5,
							  (windowSize.y/SCALE) - 2.6 - (vi.y - 1)*(50 / SCALE) );
	bodyDef.type = b2_dynamicBody; 
	m_body = world.CreateBody(&bodyDef);

	if (circle)
	{
		b2Vec2 vertices[16];
		vertices[0].Set(1.6 / 2, 0);
		vertices[1].Set(1.6*0.85, 1.6*0.15);
		vertices[2].Set(1.6, 1.6 / 2);
		vertices[3].Set(1.6*0.85, 1.6*0.85);
		vertices[4].Set(1.6 / 2, 1.6);
		vertices[5].Set(1.6*0.15, 1.6*0.85);
		vertices[6].Set(0, 1.6 / 2);
		vertices[7].Set(1.6*0.15, 1.6*0.15);

		int32 count = 8;
		octagonShape.Set(vertices, count);
	}	
	else
		boxShape.SetAsBox(((50.f / 2)*(width)) / SCALE, (50.f / 2) / SCALE,
			b2Vec2{ (50.f*width) / (2 * SCALE), (50.f) / (2 * SCALE) }, 0) ;

	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.7f;

	if (circle)
		fixtureDef.shape = &octagonShape;
	else
		fixtureDef.shape = &boxShape;

	m_body->CreateFixture(&fixtureDef);


	int i = rand() % 3;
	m_rect = sf::IntRect(188 * i, 0, 188, 130);
	m_sprite.setTextureRect(m_rect);
}

GameObject::~GameObject()
{
}

void GameObject::print(sf::RenderWindow & window)
{
	Dragons* d = dynamic_cast<Dragons*>(this);
	Guards* g = dynamic_cast<Guards*>(this);
	if (d || g)
	{
		// Creates 'animation' for dragons and guards
		if (m_spriteClock.getElapsedTime().asSeconds() > 0.3f)
		{
			if (m_rect.left == 376)
				m_rect.left = 0;
			else
				m_rect.left += 188;
			m_sprite.setTextureRect(m_rect);
			m_spriteClock.restart();

		}
	}

	m_sprite.setPosition(m_body->GetPosition().x *SCALE, m_body->GetPosition().y *SCALE);
	m_sprite.setRotation(m_body->GetAngle() * 180 / b2_pi);
	window.draw(m_sprite);

}

