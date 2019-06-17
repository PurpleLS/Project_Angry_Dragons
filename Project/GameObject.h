#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Graphics.h"

class Dragons;
class Drogon;
class Viserion;
class Rhaegal;
class NonMoveable;
class Wall;
class Wood;
class Ice;
class Rock;
class Guards;

const float SCALE = 30.f;

class GameObject
{
public:
	GameObject();
	GameObject(b2World & world, int width, sf::Vector2i position, bool circle, sf::Vector2u windowSize);
	~GameObject();
	// void print(const b2Vec2 position, float32 y);
	void print(sf::RenderWindow & window);
	sf::Sprite getSprite() const { return m_sprite; }
	bool getIfDead() { return m_dead; }
	int getType() { return m_type; }
	b2Body* getBody() { return m_body; }

	virtual void collision(GameObject& object) = 0;
	virtual void collision(Drogon & object) = 0;
	virtual void collision(Viserion& object) = 0;
	virtual void collision(Rhaegal & object) = 0;

	virtual void collision(Rock & object) = 0;
	virtual void collision(Ice & object) = 0;
	virtual void collision(Wood & object) = 0;

	virtual void collision(Guards & object) = 0;

protected:
	b2Body * m_body;
	sf::Sprite m_sprite;
	int m_width;
	int m_type = 0;
	bool m_dead = false;
	sf::IntRect m_rect;
	sf::Clock m_spriteClock;
};

