#include "Graphics.h"



Graphics::Graphics()
{
}


Graphics& Graphics::getInstance()
{
	static Graphics g;
	return g;
}

Graphics::~Graphics()
{
}
