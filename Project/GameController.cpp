#include "GameController.h"
#include "Drogon.h"
#include "Rhaegal.h"
#include "Viserion.h"

GameController::GameController()
{
}

GameController::GameController(ifstream & file)
{
	m_window.create(sf::VideoMode(100, 100), "SixColors", sf::Style::Default);
	readLevel(file);
}


GameController::~GameController()
{
}

void GameController::readLevel(ifstream & file)
{
	// Life and points always start the same, get board rows, columns and level time from file 
	int dragonsD, dragonsV, dragonsR;
	file >> dragonsD >> dragonsV >> dragonsR;

	for(int i = 0; i < dragonsD; ++i)
		m_dragons.push_back(std::make_unique<Drogon>());
	for (int i = 0; i < dragonsV; ++i)
		m_dragons.push_back(std::make_unique<Viserion>());
	for (int i = 0; i < dragonsR; ++i)
		m_dragons.push_back(std::make_unique<Rhaegal>());

	m_board.readBoard(file);
}

void GameController::run()
{

}
