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


void Board::print(sf::RenderWindow & window)
{
	// Print the objects on the board
	deleteTheDead();
	for (int i = 0; i < m_objects.size(); i++)
		m_objects[i]->print(window);
}

void Board::readBoard(ifstream & file, b2World & world , sf::RenderWindow & window)
{ 
	// Gets all the objects from a text file
	char c;
	int rows, columns;
	file >> rows >> columns;

	m_objects.clear();
	sf::Vector2i vi;

	c = file.get(); // First time get the end of line
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; ++j)
		{
			c = file.get();
			if (c == ' ')
				continue;
			int count = 1;
			char d;
			d = file.peek();
			while(c == d && c != '!')
			{
				// Check if they are longer
				count++;
				d = file.get();
				d = file.peek();
			}
			switch (c)
			{
			case '#': // Rock
				vi = sf::Vector2i(j , rows -i );
				m_objects.push_back(std::make_unique<Rock>(world, count, vi, false, window.getSize()));
				break;
			case '&': // wood
				vi = sf::Vector2i(j, rows - i);
				m_objects.push_back(std::make_unique<Wood>(world, count, vi, false, window.getSize()));
				break;
			case'@': // Ice
				vi = sf::Vector2i(j, rows - i);
				m_objects.push_back(std::make_unique<Ice>(world, count, vi, false, window.getSize()));
				break;
			case'!': // Guards
				vi = sf::Vector2i(j, rows - i);
				m_objects.push_back(std::make_unique<Guards>(world, count, vi, true, window.getSize()));
				m_guards++;
				break;
			}
			j += (count - 1);
		}
		c = file.get(); // Get the end of line
	}
}

void Board::deleteTheDead()
{
	// Erase all the objects that died
	for (int i = 0; i < m_objects.size(); ++i)
		if (m_objects[i]->getIfDead())
		{
			Guards* x = dynamic_cast<Guards*>(m_objects[i].get());
			if (x)
				m_guards--;
			m_objects[i]->getBody()->GetWorld()->DestroyBody(m_objects[i]->getBody());
			m_objects.erase(m_objects.begin() + i);
		}
}

int Board::getGuards()
{
	return m_guards;
}

void Board::clear()
{
	// Clear board
	m_objects.clear();
	m_guards = 0;
}
