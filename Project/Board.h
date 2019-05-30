#pragma once
#include <vector>
#include "GameObject.h"
#include "NonMoveable.h"
#include <memory>
#include <fstream>

using std::ifstream;

class Board
{
public:
	Board();
	~Board();
	void print(sf::RenderWindow & window, b2World & world, b2Body* bodyIterator);
	void readBoard(ifstream &file, b2World & world, sf::RenderWindow & window);
private:
	std::vector<std::unique_ptr<NonMoveable>> m_objects;
	
};

