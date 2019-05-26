#pragma once
#include <vector>
#include "GameObject.h"
#include <memory>
class Board
{
public:
	Board();
	~Board();
	void draw();
	void update_board();
private:
	std::vector<std::unique_ptr<GameObject>> m_objects;
	
};

