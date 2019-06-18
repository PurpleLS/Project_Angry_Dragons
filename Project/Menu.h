#pragma once
#include "Graphics.h"
#include <string>

using std::string;

class Menu
{
public:
	Menu();
	~Menu();
	void transitionalScreen(sf::RenderWindow & window, string text, int index);
};

