#include "GameController.h"
#include "Drogon.h"
#include "Rhaegal.h"
#include "Viserion.h"
#include "Graphics.h"
#include "Menu.h"




GameController::GameController()
{
	
}


GameController::GameController(ifstream & file)
{
	m_window.create(sf::VideoMode(/*1920, 800, 32*/), "Angry Dragons", sf::Style::Fullscreen | sf::Style::Close);
	// m_window.create(sf::VideoMode(800, 600), "Angry Dragons", sf::Style::Close);
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
	/*
	for (int i = 0; i < dragonsD; ++i)
	{
		vi = sf::Vector2i(-18  , j+1);
		m_dragons.push_back(std::make_unique<Drogon>(*m_world, 1, vi, true, m_window.getSize()));
		++j;
	}
	for (int i = 0; i < dragonsV; ++i)
	{
		vi = sf::Vector2i(-18 , j+1);
		m_dragons.push_back(std::make_unique<Viserion>(*m_world, 1, vi, true, m_window.getSize()));
		++j;
	}
	for (int i = 0; i < dragonsR; ++i)
	{
		vi = sf::Vector2i(-18, j+1);
		m_dragons.push_back(std::make_unique<Rhaegal>(*m_world, 1, vi, true, m_window.getSize()));
		++j;
	}
	*/
	while (dragonsD != 0 || dragonsV != 0 || dragonsR != 0)
	{
		int i = rand() % 3;
		if (i == 0 && dragonsD != 0)
		{
			vi = sf::Vector2i(-18, j + 1);
			m_dragons.push_back(std::make_unique<Drogon>(*m_world, 1, vi, true, m_window.getSize()));
			dragonsD--;
			++j;
		}
		else if(i == 1 && dragonsV != 0)
		{
			vi = sf::Vector2i(-18, j + 1);
			m_dragons.push_back(std::make_unique<Viserion>(*m_world, 1, vi, true, m_window.getSize()));
			dragonsV--;
			++j;
		}
		else if(i == 2 && dragonsR != 0)
		{
			vi = sf::Vector2i(-18, j + 1);
			m_dragons.push_back(std::make_unique<Rhaegal>(*m_world, 1, vi, true, m_window.getSize()));
			dragonsR--;
			++j;
		}
	}
	
}

void GameController::run()
{
	Menu menu;
	menu.openingScreen(m_window);

	b2Body* BodyIterator = m_world->GetBodyList();	
	sf::RectangleShape m_back;
	m_back.setPosition({0, 0});
	m_back.setSize({(float)m_window.getSize().x, (float)m_window.getSize().y});
	m_back.setTexture(Graphics::getInstance().getTexture(8));




	while (m_window.isOpen())
	{
		checkActive();
		m_world->Step(1/60.f, 8, 3);
		m_window.clear(sf::Color::White);
		m_window.draw(m_back);
		print();
		m_world->DrawDebugData();
		m_window.display();
		eventhandler();
	}
}

void GameController::eventhandler()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{

		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Escape)
				m_window.close();
			break;
		
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (m_dragons[m_dragons.size() - 1]->getActive())
				{
					sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
					if (m_dragons[m_dragons.size() - 1]->getSprite().getGlobalBounds().contains(mousePos))
					{
						// If the user left clicked on mouse, if the dragon is active AND if it contains the mouse pos:
						m_dragons[m_dragons.size() - 1]->setMousePositionStart(mousePos);
						float mouseX = static_cast <float>(sf::Mouse::getPosition(m_window).x);
						float mouseY = static_cast <float>(sf::Mouse::getPosition(m_window).y);
						m_dragons[m_dragons.size() - 1]->moveDragon({ mouseX , mouseY});
					}
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (m_dragons[m_dragons.size() - 1]->getActive())
			{
				sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				m_dragons[m_dragons.size() - 1]->setMousePositionEnd(mousePos);
				m_dragons[m_dragons.size() - 1]->launchDragon();
			}
			break;

		case sf::Event::MouseMoved:
			if (m_dragons[m_dragons.size() - 1]->getIfStart())
			{
				float mouseX = static_cast <float>(sf::Mouse::getPosition(m_window).x);
				float mouseY = static_cast <float>(sf::Mouse::getPosition(m_window).y);
				m_dragons[m_dragons.size() - 1]->moveDragon({ mouseX , mouseY });
			}
			break;

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

	/*
	for (;bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
	{
		GameObject* go = static_cast<GameObject*>(bodyIterator->GetUserData());
		go->print(bodyIterator->GetPosition(), bodyIterator->GetAngle());
		m_window.draw(go->getSprite());
	}
	*/

	for (int i = 0; i < m_dragons.size(); i++)
		m_dragons[i]->print(m_window);

	m_board.print(m_window);
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

	//create slingshot
	/*
	b2Body* body2;
	b2FixtureDef fixtureDef2;
	b2BodyDef bodyDef2;
	b2PolygonShape shape2;

	bodyDef2.position = b2Vec2((m_window.getSize().x / (6 * SCALE)), (m_window.getSize().y / (1.2f*SCALE)));
	bodyDef2.type = b2_staticBody;
	body2 = World.CreateBody(&bodyDef2);
	shape2.SetAsBox((50.f / 2) / SCALE, (100.f / 2) / SCALE);
	fixtureDef2.density = 0.f;
	fixtureDef2.shape = &shape2;
	body2->CreateFixture(&fixtureDef2);
	*/

}

void GameController::checkActive()
{
	bool x = false;
	for (int i = 0; i < m_dragons.size(); i++)
	{
		if (m_dragons[i]->getActive())
		{
			x = true;
			break;
		}
	}
	if (!x)
		m_dragons[m_dragons.size() - 1]->setActive(m_window.getSize().x, m_window.getSize().y); 
}
