#include "Graphics.h"



Graphics::Graphics()
{
	m_pictures.resize(8);
	m_pictures[0].loadFromFile("Pictures/wood_icon.png");
	m_pictures[1].loadFromFile("Pictures/rock_icon.png");
	m_pictures[2].loadFromFile("Pictures/ice_icon.png");
	m_pictures[3].loadFromFile("Pictures/guards_icon.png");
	m_pictures[4].loadFromFile("Pictures/drogon_icon.png");
	m_pictures[5].loadFromFile("Pictures/rhaegal_icon.png");
	m_pictures[6].loadFromFile("Pictures/viserion_icon.png");
	m_pictures[7].loadFromFile("Pictures/ground_icon.png");
}

const sf::Texture * Graphics::getTexture(int index) const
{
	if (index > 0 && index < m_pictures.size())
	{
		return &m_pictures[index];
	}
	return &m_pictures[0];//check this
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
