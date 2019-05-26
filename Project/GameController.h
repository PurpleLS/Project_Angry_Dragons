#pragma once
#include<SFML/Graphics.hpp>
#include "Dragons.h"
#include "Board.h"
#include "Menu.h"

#include <fstream>
#include <iostream>
#include <vector>

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;

class GameController
{
public:
	GameController();
	GameController(ifstream &file);
	~GameController();
	void readLevel(ifstream &file);
	void run();
	void print();
private:
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	vector<std::unique_ptr<Dragons>> m_dragons;
};

