#include "GameController.h"
#include "Drogon.h"
#include "Rhaegal.h"
#include "Viserion.h"
#include "Graphics.h"
#include "Menu.h"
#include "LevelManager.h"




GameController::GameController()
{
	m_window.create(sf::VideoMode(), "Angry Dragons", sf::Style::Fullscreen | sf::Style::Close);
	m_window.setFramerateLimit(60);
	readLevel(LevelManager::getInstance().getCurrentLevel());
}

GameController::~GameController()
{	
}

void GameController::readLevel(ifstream & file)
{
	// Creates the level based on what was in the text file
	b2Vec2 m_gravity(0.0f, 9.8f);
	m_world = std::make_unique<b2World>(m_gravity);
	m_world->SetContactListener(&myContactListenerInstance);

	// Debug draw - we can erase
	m_world->SetDebugDraw(&m_debugDrawInstance);
	uint32 flags = 0;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_centerOfMassBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_pairBit;
	flags += b2Draw::e_shapeBit;
	m_debugDrawInstance.SetFlags(flags);

	// Create borders for the screen so dragon cannot escape
	float widthInMeters = m_window.getSize().x / SCALE;
	float heightInMeters = m_window.getSize().y / SCALE;
	b2Vec2 lowerLeftCorner = b2Vec2(0, 0);
	b2Vec2 lowerRightCorner = b2Vec2(widthInMeters, 0);
	b2Vec2 upperLeftCorner = b2Vec2(0, heightInMeters);
	b2Vec2 upperRightCorner = b2Vec2(widthInMeters, heightInMeters);

	b2BodyDef screenBorderDef;
	screenBorderDef.position.Set(0, 0);
	b2Body* screenBorderBody = m_world->CreateBody(&screenBorderDef);
	b2EdgeShape screenBorderShape;

	screenBorderShape.Set(lowerLeftCorner, lowerRightCorner);
	screenBorderBody->CreateFixture(&screenBorderShape, 0);
	screenBorderShape.Set(lowerRightCorner, upperRightCorner);
	screenBorderBody->CreateFixture(&screenBorderShape, 0);
	screenBorderShape.Set(upperRightCorner, upperLeftCorner);
	screenBorderBody->CreateFixture(&screenBorderShape, 0);
	screenBorderShape.Set(upperLeftCorner, lowerLeftCorner);
	screenBorderBody->CreateFixture(&screenBorderShape, 0);

	// Life and points always start the same, get board rows, columns and level time from file 
	int dragonsD, dragonsV, dragonsR;
	file >> dragonsD >> dragonsV >> dragonsR;

	m_board.readBoard(file, *m_world, m_window);

	sf::Vector2i vi;

	// Create the dragons
	int j = 0;
	while (dragonsD != 0 || dragonsV != 0 || dragonsR != 0)
	{
		int i = rand() % 3;
		if (i == 0 && dragonsD != 0)
		{
			vi = sf::Vector2i(-14 + j, (m_window.getSize().y / 50) -1);
			m_dragons.push_back(std::make_unique<Drogon>(*m_world, 1, vi, true, m_window.getSize()));
			dragonsD--;
			++j;
		}
		else if(i == 1 && dragonsV != 0)
		{
			vi = sf::Vector2i(-14 + j, (m_window.getSize().y / 50) - 1);
			m_dragons.push_back(std::make_unique<Viserion>(*m_world, 1, vi, true, m_window.getSize()));
			dragonsV--;
			++j;
		}
		else if(i == 2 && dragonsR != 0)
		{
			vi = sf::Vector2i(-14 + j, (m_window.getSize().y / 50) - 1);
			m_dragons.push_back(std::make_unique<Rhaegal>(*m_world, 1, vi, true, m_window.getSize()));
			dragonsR--;
			++j;
		}
	}
	createGround(*m_world, 400.f, 500.f);
}

void GameController::run()
{
	// Start the game
	m_menu.transitionalScreen(m_window, "play", 9);
	m_menu.viewMap(m_window);

	sf::RectangleShape m_back;
	m_back.setPosition({0, 0});
	m_back.setSize({(float)m_window.getSize().x, (float)m_window.getSize().y});
	m_back.setTexture(Graphics::getInstance().getTexture(8));




	while (m_window.isOpen())
	{
		if (checkEndLevel())
		{
			m_menu.viewMap(m_window);
			m_menu.transitionalScreen(m_window, "You Won", 9);
			// gameOver - levels end 
			break;
		}
		checkActive();
		m_world->Step(1/60.f, 8, 3);
		m_window.clear(sf::Color::White);
		m_window.draw(m_back);
		print();
		// m_world->DrawDebugData(); // Debug draw - we can erase
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
						if (!m_dragons[m_dragons.size() - 1]->getIfDead()) 
						{// If the user left clicked on mouse, if the dragon is active AND if it contains the mouse pos:
							m_dragons[m_dragons.size() - 1]->setMousePositionStart(mousePos);
							float mouseX = static_cast <float>(sf::Mouse::getPosition(m_window).x);
							float mouseY = static_cast <float>(sf::Mouse::getPosition(m_window).y);
							if(mouseY > m_window.getSize().y - 20)
								m_dragons[m_dragons.size() - 1]->moveDragon({ mouseX , mouseY });
						}
					}
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (m_dragons[m_dragons.size() - 1]->getActive() && m_dragons[m_dragons.size() - 1]->getIfStart())
			{
				// The user let go of the dragon (after dragging it)
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
	// Prints the world and bodies
	b2Body* bodyIterator = m_world->GetBodyList();

	m_groundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);//updates position
	m_groundSprite.setRotation(180 / b2_pi * bodyIterator->GetAngle());//updates rotation
	m_window.draw(m_groundSprite);
	bodyIterator = bodyIterator->GetNext();

	for (int i = 0; i < m_dragons.size(); i++)
		m_dragons[i]->print(m_window);

	m_board.print(m_window);
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

	m_groundSprite.setOrigin(960.f, 25.f);
}

void GameController::checkActive()
{
	// Check which of the dragons is active 
	bool x = false;
	if (m_dragons[m_dragons.size()-1]->getActive())
	{
		if (!m_dragons[m_dragons.size() - 1]->checkMovement())
		{
			m_dragons.pop_back();
		}
		else
			x = true;
	}
	else if(!x && m_dragons.size() > 0)
		m_dragons[m_dragons.size() - 1]->setActive(m_window.getSize().x, m_window.getSize().y); 
}

bool GameController::checkEndLevel()
{
	// Check if the level has ended 
	if (m_board.getGuards() == 0)
	{
		// User beat level, get the next one
		if (m_clock.getElapsedTime().asSeconds() > 2.f)
		{
			if (LevelManager::getInstance().gameOver())
				return true;

			// next level

			m_menu.transitionalScreen(m_window, "Next Level", 10);

			m_world.release();
			m_dragons.clear();
			m_board.clear();

			if (m_world.get() == nullptr)
				cout << "new level" << endl;
			else
				cout << " World was NOT released" << endl;

			readLevel(LevelManager::getInstance().getNextLevel());
			m_menu.viewMap(m_window);
		}
	}
	else
		m_clock.restart();
	if (m_dragons.size() == 0)
	{
		// User failed, load the same level again
		m_menu.transitionalScreen(m_window, "Try Again", 11);
		m_menu.viewMap(m_window);

		m_world.release();
		m_dragons.clear();
		m_board.clear();

		if (m_world.get() == nullptr)
			cout << "new level" << endl;
		else
			cout << " World was NOT released" << endl;

		readLevel(LevelManager::getInstance().getCurrentLevel());
		m_menu.viewMap(m_window);
	}
	return false;
}

