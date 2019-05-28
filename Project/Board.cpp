#include "Board.h"
#include "Rock.h"
#include "Wood.h"
#include "Ice.h"
#include "Guards.h"



Board::Board()
{
}


Board::~Board()
{
}

void Board::print(sf::RenderWindow & window, b2World* world)
{
	b2Body* BodyIterator = world->GetBodyList();
	for (int i = 0; i < m_objects.size(); ++i)
	{
		m_objects[i]->print(BodyIterator->GetPosition(), BodyIterator->GetAngle());
		window.draw(m_objects[i]->getSprite());
	}
}

void Board::readBoard(ifstream & file, b2World* world)
{
	char c;
	int rows, columns;
	file >> rows >> columns;

	m_objects.clear();

	c = file.get(); // First time get the end of line
	for (float i = 0; i < rows; i++)
	{
		for (float j = 0; j < columns; j++)
		{
			c = file.get();
			int count = 1;
			char d;
			d = file.peek();
			while(c == d)
			{
				count++;
				d = file.get();
				d = file.peek();
			}
			switch (c)
			{
			case '#': // Rock
				m_objects.push_back(std::make_unique<Rock>(world, count, sf::Vector2f(i,j)));
				break;
			case '&': // wood
				m_objects.push_back(std::make_unique<Wood>(world, count, sf::Vector2f(i, j)));
			case'@': // Ice
				m_objects.push_back(std::make_unique<Ice>(world, count, sf::Vector2f(i, j)));
				break;
			case'!': // Guards
				m_objects.push_back(std::make_unique<Guards>(world, count, sf::Vector2f(i, j)));
				break;
			case' ':
				break;
			}
			j += count;
		}
		c = file.get(); // Get the end of line
	}
}
