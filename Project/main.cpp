#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
//--------
#include <Windows.h>
#include "Graphics.h"

using std::ifstream;
using std::cout;
using std::endl;

int main() 
{
	srand((unsigned)time(0));
	// Open file
	
	/*ifstream file("level1.txt");
	if (!file.is_open())
	{
		cout << "The file could not open " << endl;
		return EXIT_FAILURE;
	}*/
	
	GameController game;
	game.run();
    

/*
	//--------------------------------
	sf::RenderWindow window;
	window.create(sf::VideoMode(1920, 800, 32), "Angry Dragons", sf::Style::Close);
	window.setFramerateLimit(60);

	b2Vec2 m_gravity(0.0f, 9.8f);
	b2World world(m_gravity);

	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2CircleShape circleShape;
	b2PolygonShape boxShape;
	// b2Body body;

	bodyDef.position = b2Vec2(0,0);
	bodyDef.type = b2_dynamicBody; // b2_staticBody; //b2_dynamicBody;
	b2Body* m_body = world.CreateBody(&bodyDef);

	boxShape.SetAsBox(((50.f / 2)/ SCALE), (50.f / 2)/ SCALE);

	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.7f;

	fixtureDef.shape = &boxShape;

	m_body->CreateFixture(&fixtureDef);

	while (window.isOpen())
	{
		world.Step(1 / 60, 8, 3);
		window.clear(sf::Color::White);

		for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
		{
			if (bodyIterator->GetType() == b2_dynamicBody)
			{
				sf::Sprite sprite;
				sprite.setTexture(*Graphics::getInstance().getTexture(4));
				sprite.setOrigin(25.f, 25.f);
				sprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y* SCALE);

				cout << bodyIterator->GetPosition().x << " " << bodyIterator->GetPosition().y << endl;

				sprite.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
				window.draw(sprite);
				window.display();
			}
		}
	//	sf::RectangleShape shape;
	//	shape.setFillColor(sf::Color::Red);
	//	sf::Vector2f vector;
	//	vector.x = m_body->GetPosition().x;
	//	vector.y = m_body->GetPosition().y;
	//	b2Body* bodyIterator = world.GetBodyList();
	//	shape.setPosition(bodyIterator->GetPosition().x *2, bodyIterator->GetPosition().y * 2);
	//	float f = m_body->GetGravityScale();
	//	shape.setScale(f, f);
	//	shape.setSize(sf::Vector2f(50, 50));
	//	window.draw(shape);
	//	window.display();
	// 	Sleep(3);
	}
*/
	return EXIT_SUCCESS;
};