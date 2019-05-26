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

void Board::readBoard(ifstream & file)
{
	int rows, columns;
	file >> rows >> columns;

	m_objects.clear();

	char c;
	c = file.get(); // First time get the end of line
	for (float i = 0; i < rows; i++)
	{
		for (float j = 0; j < columns; j++)
		{
			c = file.get();
			switch (c)
			{
			case '#': // Wall
				m_objects.push_back(std::make_unique<Rock>()); // send position by i, j
				break;
			case '&': // wood
				m_objects.push_back(std::make_unique<Wood>());// send position by i, j
			case'@': // Ice
				m_objects.push_back(std::make_unique<Ice>());// send position by i, j
				break;
			case'!': // Guards
				m_objects.push_back(std::make_unique<Guards>());// send position by i, j
				break;
			case' ':
				break;
			}
		}
		c = file.get(); // Get the end of line
	}
}
