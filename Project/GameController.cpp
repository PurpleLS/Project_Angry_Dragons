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
	readLevel(file);

	b2Vec2 m_gravity(0.0f, 9.8f);
	m_world = std::make_unique<b2World>(m_gravity);
	
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
		m_dragons.push_back(std::make_unique<Drogon>());
	for (int i = 0; i < dragonsV; ++i)
		m_dragons.push_back(std::make_unique<Viserion>());
	for (int i = 0; i < dragonsR; ++i)
		m_dragons.push_back(std::make_unique<Rhaegal>());

	m_board.readBoard(file);
}

void GameController::run()
{
		b2Body* BodyIterator = m_world->GetBodyList();
		sf::Sprite GroundSprite;
		sf::Texture GroundTexture;
		GroundTexture.loadFromFile("ground.png");
		GroundSprite.setTexture(GroundTexture);
		GroundSprite.setOrigin(400.f, 8.f);
		GroundSprite.setScale(1920 / GroundSprite.getGlobalBounds().width, 800 / GroundSprite.getGlobalBounds().height);
		
		
	while (m_window.isOpen())
	{
		m_world->Step(1 / 60.f, 8, 3);
		m_window.clear();

		GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);//updates position
		GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());//updates rotation
		m_window.draw(GroundSprite);
		m_window.display();
	}
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
