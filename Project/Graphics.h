#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include<Box2D/Box2D.h>

class Graphics
{
public:
	static Graphics& getInstance();
	~Graphics();
private:
	Graphics();
	Graphics(const Graphics & x) = delete;
	Graphics operator=(const Graphics & x) = delete;
	static Graphics* instance;
public:
	
};

