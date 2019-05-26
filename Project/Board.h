#pragma once
#include <vector>
#include "GameObject.h"
#include "NonMoveable.h"
#include <memory>
#include <fstream>

using std::ifstream;

class Board
{
public:
	Board();
	~Board();
	void draw();
	void readBoard(ifstream &file);
private:
	std::vector<std::unique_ptr<NonMoveable>> m_objects;
	
};

