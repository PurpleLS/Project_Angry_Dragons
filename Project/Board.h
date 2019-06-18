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
	// void print(sf::RenderWindow & window, b2World & world, b2Body* bodyIterator);
	void print(sf::RenderWindow & window);
	void readBoard(ifstream &file, b2World & world, sf::RenderWindow & window);
	void deleteTheDead();
	int getGuards();
	void clear();
private:
	std::vector<std::unique_ptr<NonMoveable>> m_objects;
	int m_guards=0;
};

