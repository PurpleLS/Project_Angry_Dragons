#include "GameController.h"
#include "Drogon.h"
#include "Rhaegal.h"
#include "Viserion.h"



GameController::GameController()
{
	
}


GameController::GameController(ifstream & file)
{
	m_window.create(sf::VideoMode(1920, 800), "Angry Dragons", sf::Style::Close);

	b2Vec2 m_gravity(0.0f, 9.8f);
	m_world = std::make_unique<b2World>(m_gravity);

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

	for(int i = 0; i < dragonsD; ++i)
		m_dragons.push_back(std::make_unique<Drogon>(m_world.get(), 1, sf::Vector2f(0, 0)));
	for (int i = 0; i < dragonsV; ++i)
		m_dragons.push_back(std::make_unique<Viserion>(m_world.get(), 1, sf::Vector2f(0, 0)));
	for (int i = 0; i < dragonsR; ++i)
		m_dragons.push_back(std::make_unique<Rhaegal>(m_world.get(), 1, sf::Vector2f(0, 0)));

	m_board.readBoard(file, m_world.get());
}

void GameController::run()
{
		b2Body* BodyIterator = m_world->GetBodyList();
		sf::Sprite GroundSprite;
		GroundSprite.setTexture(*Graphics::getInstance().getTexture(7));
		GroundSprite.setOrigin(400.f, -2100.f);
		GroundSprite.setScale(1920 / GroundSprite.getGlobalBounds().width, 100 / GroundSprite.getGlobalBounds().height);
		
		
	while (m_window.isOpen())
	{
		m_world->Step(1 / 60.f, 8, 3);
		m_window.clear(sf::Color::White);

		GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);//updates position
		GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());//updates rotation
		m_window.draw(GroundSprite);
		print();
		m_window.display();
	}
}

void GameController::print()
{
	b2Body* BodyIterator = m_world->GetBodyList();
	for (int i = 0; i < m_dragons.size(); ++i)
	{
		m_dragons[i]->print(BodyIterator->GetPosition(), BodyIterator->GetAngle());
		m_window.draw(m_dragons[i]->getSprite());
	}
	m_board.print(m_window, m_world.get());
}

//creates ground
void GameController::createGround(b2World & World, float X, float Y)
{
	b2Body* body;
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2PolygonShape shape;

	bodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
	bodyDef.type = b2_staticBody;
	body = World.CreateBody(&bodyDef);
	
	shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
	fixtureDef.density = 0.0f;
	fixtureDef.shape = &shape;
	body->CreateFixture(&fixtureDef);

}
