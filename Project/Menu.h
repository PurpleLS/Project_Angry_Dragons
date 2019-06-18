#pragma once
#include "Graphics.h"
#include "LevelManager.h"
#include <string>

using std::string;

class Menu
{
public:
	Menu();
	~Menu();
	void transitionalScreen(sf::RenderWindow & window, string text, int index);
	void viewMap(sf::RenderWindow & window);
};

