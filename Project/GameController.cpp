#include "GameController.h"
#include "Drogon.h"
#include "Rhaegal.h"
#include "Viserion.h"
#include "Graphics.h"



GameController::GameController()
{
	
}


GameController::GameController(ifstream & file)
{
   	m_window.create(sf::VideoMode(/*1920, 800, 32*/), "Angry Dragons", sf::Style::Fullscreen | sf::Style::Close);
	// m_window.create(sf::VideoMode(800, 600, 32), "Angry Dragons", sf::Style::Close);
	m_window.setFramerateLimit(60);

	b2Vec2 m_gravity(0.0f, 9.8f);
	m_world = std::make_unique<b2World>(m_gravity);
	
	
	m_world->SetDebugDraw(&m_debugDrawInstance);
	uint32 flags = 0;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_centerOfMassBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_pairBit;
	flags += b2Draw::e_shapeBit;
	m_debugDrawInstance.SetFlags(flags);


	readLevel(file);

	createGround(*m_world, 400.f, 500.f);
}


GameController::~GameController()
{	
}


void GameController::readLevel(ifstream & file)
{
	// Life and points always start the same, get board rows, columns and level time from file 
	int dragonsD, dragonsV, dragonsR;
	file >> dragonsD >> dragonsV >> dragonsR;

	m_board.readBoard(file, *m_world, m_window);

	sf::Vector2i vi;

	int j = 0;
	for (int i = 0; i < dragonsD; ++i)
	{
		vi = sf::Vector2i(j - 18 , 1);
		m_dragons.push_back(std::make_unique<Drogon>(*m_world, 1, vi, true, m_window.getSize()));
		++j;
	}
	for (int i = 0; i < dragonsV; ++i)
	{
		vi = sf::Vector2i(j - 18, 1);
		m_dragons.push_back(std::make_unique<Viserion>(*m_world, 1, vi, true, m_window.getSize()));
		++j;
	}
	for (int i = 0; i < dragonsR; ++i)
	{
		vi = sf::Vector2i(j - 18, 1);
		m_dragons.push_back(std::make_unique<Rhaegal>(*m_world, 1, vi, true, m_window.getSize()));
		++j;
	}

}

void GameController::run()
{
	b2Body* BodyIterator = m_world->GetBodyList();	
	sf::RectangleShape m_back;
	m_back.setPosition({0, 0});
	m_back.setSize({(float)m_window.getSize().x, (float)m_window.getSize().y});
	m_back.setTexture(Graphics::getInstance().getTexture(8));




	while (m_window.isOpen())
	{
		m_world->Step(1/60.f, 8, 3);
		m_window.clear(sf::Color::White);
		m_window.draw(m_back);
		print();
		m_world->DrawDebugData();
		m_window.display();

		for (sf::Event event; m_window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed )
				m_window.close();
			if(event.type == sf::Event::KeyReleased)
				if(event.key.code == sf::Keyboard::Escape)
					m_window.close();
		}
	}
}

void GameController::print()
{
	b2Body* bodyIterator = m_world->GetBodyList();

	m_groundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);//updates position
	m_groundSprite.setRotation(180 / b2_pi * bodyIterator->GetAngle());//updates rotation
	m_window.draw(m_groundSprite);
	bodyIterator = bodyIterator->GetNext();

	for (;bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
	{
		GameObject* go = static_cast<GameObject*>(bodyIterator->GetUserData());
		go->print(bodyIterator->GetPosition(), bodyIterator->GetAngle());
		m_window.draw(go->getSprite());
	}
	
	/*
	b2Body* bodyIterator = m_world->GetBodyList();
	
	m_groundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);//updates position
	m_groundSprite.setRotation(180 / b2_pi * bodyIterator->GetAngle());//updates rotation

	m_window.draw(m_groundSprite);
	// std::cout << bodyIterator->GetPosition().x  << " " << bodyIterator->GetPosition().y << endl;
	GameObject* go = static_cast<GameObject*>(bodyIterator->GetUserData());

	bodyIterator = bodyIterator->GetNext();
	for (int i = 0; bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
	{
		m_dragons[i]->print(bodyIterator->GetPosition(), bodyIterator->GetAngle());
		m_window.draw(m_dragons[i]->getSprite());
		i++;
		if (i >= m_dragons.size())
			break;
	}
	m_board.print(m_window, *m_world, bodyIterator);
	*/
}

//creates ground
void GameController::createGround(b2World & World, float X, float Y)
{
	b2Body* body;
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2PolygonShape shape;

	bodyDef.position = b2Vec2(960 / SCALE,  m_window.getSize().y * (7/5) / SCALE);
	bodyDef.type = b2_staticBody;
	body = World.CreateBody(&bodyDef);
	shape.SetAsBox((1920.f / 2) / SCALE, ( 50.f / 2) / SCALE);
	fixtureDef.density = 0.f;
	fixtureDef.shape = &shape;
	body->CreateFixture(&fixtureDef);

	m_groundSprite.setTexture(*Graphics::getInstance().getTexture(7));

	m_groundSprite.setOrigin(960.f, 25.f); // ????????????
	// m_groundSprite.setScale(1920 / m_groundSprite.getGlobalBounds().width, 100 / m_groundSprite.getGlobalBounds().height);

}
