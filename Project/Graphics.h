#pragma once
class Graphics
{
public:
	static Graphics* getInstance();
	~Graphics();
private:
	Graphics();
	static Graphics* instance;
};

