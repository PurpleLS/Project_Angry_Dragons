#pragma once
#include "Dragons.h"
#include <vector>
#include <memory>

class Player
{
public:
	Player();
	~Player();
	void update_score();
	void update_dragons();

private:
	int m_score;
	std::vector<std::unique_ptr<Dragons>> dragons_left;
};

