#include "GameController.h"
#include "Drogon.h"
#include "Rhaegal.h"
#include "Viserion.h"



GameController::GameController()
{
	
}


GameController::GameController(ifstream & file)
{
	m_window.create(sf::VideoMode(800, 600, 32), "Angry Dragons", sf::Style::Close);
	m_window.setFramerateLimit(60);

	b2Vec2 m_gravity(0.0f, 9.8f);
	m_world = std::make_unique<b2World>(m_gravity);

	readLevel(file);

	createGround(*m_world, 400.f, 701.f);

	
}


GameController::~GameController()
{	
}


void GameController::readLevel(ifstream & file)
{
	// Life and points always start the same, get board rows, columns and level time from file 
	int dragonsD, dragonsV, dragonsR;
	file >> dragonsD >> dragonsV >> dragonsR;

	m_board.readBoard(file, *m_world);

	int j = 0;
	for(int i = 0; i < dragonsD; ++i)
 		m_dragons.push_back(std::make_unique<Drogon>(*m_world, 1, sf::Vector2f(10.f, j*10.f),true));
	j += dragonsD;
	for (int i = 0; i < dragonsV; ++i)
		m_dragons.push_back(std::make_unique<Viserion>(*m_world, 1, sf::Vector2f(10.f, i * 10.f), true));
	j += dragonsV;
	for (int i = 0; i < dragonsR; ++i)
		m_dragons.push_back(std::make_unique<Rhaegal>(*m_world, 1, sf::Vector2f(10.f, i * 10.f), true));

}

void GameController::run()
{
	b2Body* BodyIterator = m_world->GetBodyList();	

	while (m_window.isOpen())
	{
		m_world->Step(1/120.f, 8, 3);
		m_window.clear(sf::Color::White);
		print();
		m_window.display();

		for (sf::Event event; m_window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}
	}
}

void GameController::print()
{
	b2Body* bodyIterator = m_world->GetBodyList();
	
	m_groundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);//updates position
	m_groundSprite.setRotation(180 / b2_pi * bodyIterator->GetAngle());//updates rotation

	m_window.draw(m_groundSprite);
	std::cout << bodyIterator->GetPosition().x  << " " << bodyIterator->GetPosition().y << endl;

	bodyIterator = bodyIterator->GetNext();

	for (int i = 0; bodyIterator; bodyIterator = bodyIterator->GetNext())
	{
		if (i >= m_dragons.size())
			break;
		m_dragons[i]->print(bodyIterator->GetPosition(), bodyIterator->GetAngle());
		m_window.draw(m_dragons[i]->getSprite());
		i++;
	}
	m_board.print(m_window, *m_world, bodyIterator);
}

//creates ground
void GameController::createGround(b2World & World, float X, float Y)
{
	b2Body* body;
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2PolygonShape shape;

	bodyDef.position = b2Vec2(400 / SCALE, 500 / SCALE); //   400.f, 701.f)
	bodyDef.type = b2_staticBody;
	body = World.CreateBody(&bodyDef);
	shape.SetAsBox((800.f / 2) / SCALE, ( 16.f / 2) / SCALE); // /SCALE
	fixtureDef.density = 0.0f;
	fixtureDef.shape = &shape;
	body->CreateFixture(&fixtureDef);

	m_groundSprite.setTexture(*Graphics::getInstance().getTexture(7));

	m_groundSprite.setOrigin(400.f, 8.f);
	// m_groundSprite.setScale(1920 / m_groundSprite.getGlobalBounds().width, 100 / m_groundSprite.getGlobalBounds().height);

	/*
		b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2CircleShape circleShape;
	b2PolygonShape boxShape;
	if (circle)
		circleShape.m_radius = 10;
	else
		boxShape.SetAsBox((50.f / 2) / SCALE, (50.f / 2) / SCALE);

	bodyDef.position = b2Vec2(position.x/ SCALE, position.y/ SCALE);
	bodyDef.type = b2_dynamicBody;
	m_body = world.CreateBody(&bodyDef);

	//circleShape.m_p.Set(0, 0); //position, relative to body position
	// Shape.m_radius = 10;
	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.7f;
	if (circle)
		fixtureDef.shape = &circleShape;
	else
		fixtureDef.shape = &boxShape;

	m_body->CreateFixture(&fixtureDef);
	m_sprite.setPosition(position);
	*/

}
