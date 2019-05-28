#include "Graphics.h"



Graphics::Graphics()
{
}

const sf::Texture * Graphics::getTexture(int index) const
{
	if (index > 0 && index < m_pictures.size())
	{
		return &m_pictures[index];
	}
	return NULL;//check this
}

const sf::Font * Graphics::getFont() const
{
	return &m_font;
}

//const sf::Sound * Graphics::getSound(int index) const
//{
//	if (index > 0 && index < m_sounds.size())
//	{
//		return &m_sounds[index];
//	}
//	return NULL;//check this
//}
//
//const sf::Music * Graphics::getMusic() const
//{
//	return &m_music;
//}


Graphics& Graphics::getInstance()
{
	static Graphics g;
	return g;
}

Graphics::~Graphics()
{
}
