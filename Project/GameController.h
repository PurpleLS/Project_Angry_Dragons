#pragma once
#include<SFML/Graphics.hpp>
#include "Dragons.h"
#include "Board.h"
#include "Menu.h"
#include "Graphics.h"
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include "Box2D/Box2D.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;

//const float SCALE = 30.f;

class GameController
{
public:
	GameController();
	GameController(ifstream &file);
	~GameController();
	void readLevel(ifstream &file);
	void run();
	void print();
	void createGround(b2World& World, float X, float Y);
private:
	std::unique_ptr<b2World> m_world;
	
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	vector<std::unique_ptr<Dragons>> m_dragons;
};

