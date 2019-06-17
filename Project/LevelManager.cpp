#include "LevelManager.h"


LevelManager & LevelManager::getInstance()
{
	static LevelManager instance;
	return instance;
}

LevelManager::~LevelManager()
{
}

LevelManager::LevelManager()
{
}
