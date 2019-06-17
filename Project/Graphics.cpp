#include "Graphics.h"

#include <iostream>

Graphics::Graphics()
{
	m_pictures.resize(10);
	if (!m_pictures[0].loadFromFile("Pictures/wood_icon.png")   ) { std::cerr << "error in loading picture 0\n";};
	if (!m_pictures[1].loadFromFile("Pictures/rock_icon.jpg")   ) { std::cerr << "error in loading picture 1\n";};
	if (!m_pictures[2].loadFromFile("Pictures/ice_icon.jpg")    ) { std::cerr << "error in loading picture 2\n";};
	if (!m_pictures[3].loadFromFile("Pictures/guards_icon.png") ) { std::cerr << "error in loading picture 3\n";};
	if (!m_pictures[4].loadFromFile("Pictures/dragon1_icon1.png")) { std::cerr << "error in loading picture 4\n";};
	if (!m_pictures[5].loadFromFile("Pictures/dragon2_icon2.png")) { std::cerr << "error in loading picture 5\n";}; // rhaegal
	if (!m_pictures[6].loadFromFile("Pictures/dragon3_icon3.png")) { std::cerr << "error in loading picture 6\n";}; // viserion
	if (!m_pictures[7].loadFromFile("Pictures/ground_icon.png") ) { std::cerr << "error in loading picture 7\n";}; // ground
	if (!m_pictures[8].loadFromFile("Pictures/background_icon.png")) { std::cerr << "error in loading picture 8\n"; };
	if (!m_pictures[9].loadFromFile("Pictures/backgroundStart_icon.jpeg")) { std::cerr << "error in loading picture 9\n"; };

	if (!m_font.loadFromFile("Fonts/planet-benson/planetbe.ttf")) { std::cerr << "error in loading Font\n"; };

	if (!m_music.openFromFile("Audio/Opening.wav")) { std::cerr << "error in loading sound\n"; };
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


Graphics& Graphics::getInstance()
{
	static Graphics instance;
	return instance;
}

Graphics::~Graphics()
{
}
