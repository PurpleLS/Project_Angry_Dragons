#pragma once
#include <iostream>
#include <fstream>
#include <string>
// #include <cstdlib>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

const int MAX_LEVELS = 5;

class LevelManager
{
public:
	static LevelManager& getInstance();
	~LevelManager();
	ifstream & getNextLevel();
	ifstream & getCurrentLevel();
	int getIndexLevel() { return m_levelIndex; }
	bool gameOver();


private:
	LevelManager();
	LevelManager(const LevelManager & x) = delete;
	LevelManager operator=(const LevelManager & x) = delete;
	
	int m_levelIndex = 1;
	ifstream m_file;
};

