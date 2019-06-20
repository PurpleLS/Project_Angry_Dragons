#include "Graphics.h"

#include <iostream>

std::vector<sf::Sound> Graphics::m_sounds;

Graphics::Graphics()
{
	// Load all the pictures, font, music and sounds
	m_pictures.resize(24);
	if (!m_pictures[0].loadFromFile("Pictures/wood_icon.png")   ) { std::cerr << "error in loading picture 0\n";};
	if (!m_pictures[1].loadFromFile("Pictures/rock_icon.png")   ) { std::cerr << "error in loading picture 1\n";};
	if (!m_pictures[2].loadFromFile("Pictures/ice_icon.jpg")    ) { std::cerr << "error in loading picture 2\n";};
	if (!m_pictures[3].loadFromFile("Pictures/guards_icon3.png") ) { std::cerr << "error in loading picture 3\n";};
	if (!m_pictures[4].loadFromFile("Pictures/dragon1_icon1.png")) { std::cerr << "error in loading picture 4\n";};
	if (!m_pictures[5].loadFromFile("Pictures/dragon2_icon2.png")) { std::cerr << "error in loading picture 5\n";}; // rhaegal
	if (!m_pictures[6].loadFromFile("Pictures/dragon3_icon3.png")) { std::cerr << "error in loading picture 6\n";}; // viserion
	if (!m_pictures[7].loadFromFile("Pictures/ground_icon.png") ) { std::cerr << "error in loading picture 7\n";}; // ground
	if (!m_pictures[8].loadFromFile("Pictures/background_icon.png")) { std::cerr << "error in loading picture 8\n"; };
	if (!m_pictures[9].loadFromFile("Pictures/backgroundStart_icon1.jpg")) { std::cerr << "error in loading picture 9\n"; };
	if (!m_pictures[10].loadFromFile("Pictures/level_cleared.jpg")) { std::cerr << "error in loading picture 10\n"; };
	if (!m_pictures[11].loadFromFile("Pictures/fail.jpg")) { std::cerr << "error in loading picture 11\n"; };

	if (!m_pictures[12].loadFromFile("Pictures/map1.jpg")) { std::cerr << "error in loading picture 12\n"; };
	if (!m_pictures[13].loadFromFile("Pictures/map2.jpg")) { std::cerr << "error in loading picture 13\n"; };
	if (!m_pictures[14].loadFromFile("Pictures/map3.jpg")) { std::cerr << "error in loading picture 14\n"; };
	if (!m_pictures[15].loadFromFile("Pictures/map4.jpg")) { std::cerr << "error in loading picture 15\n"; };
	if (!m_pictures[16].loadFromFile("Pictures/map5.jpg")) { std::cerr << "error in loading picture 16\n"; };
	if (!m_pictures[17].loadFromFile("Pictures/map6.jpg")) { std::cerr << "error in loading picture 17\n"; };

	if (!m_pictures[18].loadFromFile("Pictures/ice_icon_cracked.png")) { std::cerr << "error in loading picture 18\n"; };
	if (!m_pictures[19].loadFromFile("Pictures/rock_icon_cracked.png")) { std::cerr << "error in loading picture 19\n"; };
	if (!m_pictures[20].loadFromFile("Pictures/wood_icon_cracked.png")) { std::cerr << "error in loading picture 20\n"; };
	if (!m_pictures[21].loadFromFile("Pictures/guards_icon4.png")) { std::cerr << "error in loading picture 21\n"; };
	if (!m_pictures[22].loadFromFile("Pictures/throne_won.png")) { std::cerr << "error in loading picture 22\n"; };
	if (!m_pictures[23].loadFromFile("Pictures/help_icon.png")) { std::cerr << "error in loading picture 23\n"; };

	if (!m_font.loadFromFile("Fonts/planet-benson/planetbe.ttf")) { std::cerr << "error in loading Font\n"; };

	if (!m_music.openFromFile("Audio/Opening.wav")) { std::cerr << "error in loading music\n"; };
	m_music.setLoop(true);

	m_buffers.resize(5);
	if (!m_buffers[0].loadFromFile("Audio/sound_slingshot.wav")){ std::cerr << "error in loading sound to buffer 0\n"; }
	if (!m_buffers[1].loadFromFile("Audio/sound_break.wav")) { std::cerr << "error in loading sound to buffer 0\n"; }
	if (!m_buffers[2].loadFromFile("Audio/sound_die.wav")) { std::cerr << "error in loading sound to buffer 0\n"; }
	if (!m_buffers[3].loadFromFile("Audio/sound_fly.wav")) { std::cerr << "error in loading sound to buffer 0\n"; }
	if (!m_buffers[4].loadFromFile("Audio/sound_hit.wav")) { std::cerr << "error in loading sound to buffer 0\n"; }
	
	m_sounds.resize(5);
	for (int i = 0; i < m_buffers.size(); ++i)
	{
		m_sounds[i].setBuffer(m_buffers[i]);
		m_sounds[i].setVolume(100);
	}
	m_sounds[1].setVolume(5);
	m_sounds[4].setVolume(5);
}

const sf::Texture * Graphics::getTexture(int index) const
{
	if (index > 0 && index < m_pictures.size())
	{
		return &m_pictures[index];
	}
	return &m_pictures[0];
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
