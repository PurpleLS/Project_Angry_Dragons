#pragma once
#include "Box2D/Box2D.h"
#include <SFML/Graphics.hpp>



const float SCALE = 30.f;

class GameObject
{
public:
	GameObject();
	GameObject(b2World* world, int width, sf::Vector2f postion);
	~GameObject();
private:
	b2Body* m_body;
	sf::Sprite m_sprite;
};

