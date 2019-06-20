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
#include "b2GLDraw.h"
#include "MyContactListener.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;

class GameController
{
public:
	GameController();
	void run();
	~GameController();

private:
	void readLevel(ifstream &file);
	void eventhandler();
	void print();
	void createGround(b2World& World, float X, float Y);
	void checkActive();
	bool checkEndLevel();
	sf::Clock m_clock;


	// b2GLDraw m_debugDrawInstance;
	std::unique_ptr<b2World> m_world;
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	vector<std::unique_ptr<Dragons>> m_dragons;
	sf::Sprite m_groundSprite;
	MyContactListener myContactListenerInstance;
};