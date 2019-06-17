#pragma once
class LevelManager
{
public:
	static LevelManager& getInstance();
	~LevelManager();

private:
	LevelManager();
	LevelManager(const LevelManager & x) = delete;
	LevelManager operator=(const LevelManager & x) = delete;
	// static LevelManager* m_instance;
};

