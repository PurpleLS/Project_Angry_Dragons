#include "LevelManager.h"

LevelManager & LevelManager::getInstance()
{
	static LevelManager instance;
	return instance;
}

LevelManager::~LevelManager()
{
}

ifstream & LevelManager::getNextLevel()
{
	m_levelIndex++;
	if (m_file.is_open())
		m_file.close();
	string fileName = "level" + to_string(m_levelIndex) + ".txt";
	m_file.open(fileName);
	if (!m_file.is_open())
	{
		cout << "The file could not open " << endl;
		exit(EXIT_FAILURE);
	}
	return m_file;
}

ifstream & LevelManager::getCurrentLevel()
{
	if(m_file.is_open())
		m_file.close();
	string fileName = "level" + to_string(m_levelIndex) + ".txt";
	m_file.open(fileName);
	if (!m_file.is_open())
	{
		cout << "The file could not open " << endl;
		exit(EXIT_FAILURE);
	}
	return m_file;
}

bool LevelManager::gameOver()
{
	if (m_levelIndex < MAX_LEVELS)
		return false;
	m_levelIndex++;
	return true;
}

LevelManager::LevelManager()
{
	m_file = ifstream("level1.txt");
	if (!m_file.is_open())
	{
		cout << "The file could not open " << endl;
		exit(EXIT_FAILURE);
	}
	m_levelIndex = 1;
}
