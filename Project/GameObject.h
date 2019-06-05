#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Graphics.h"



const float SCALE = 10.f;

class GameObject
{
public:
	GameObject();
	GameObject(b2World & world, int width, sf::Vector2i postion, bool circle);
	~GameObject();
	void print(const b2Vec2 position, float32 y);
	sf::Sprite getSprite() const { return m_sprite; }
protected:
	b2Body* m_body;
	sf::Sprite m_sprite;
	int m_width;
};

