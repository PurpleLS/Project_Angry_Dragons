#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
//--------
#include <Windows.h>
#include "Graphics.h"

using std::ifstream;
using std::cout;
using std::endl;

int main() 
{
	srand((unsigned)time(0));
	
	GameController game;
	game.run();
    
	return EXIT_SUCCESS;
};