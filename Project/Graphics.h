#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>

class Graphics
{
public:
	static Graphics& getInstance();
	~Graphics();
	const sf::Texture* getTexture(int index) const;
	// const sf::Sound* getSound(int index) const;
	// const sf::Music* getMusic() const;
	const sf::Font* getFont() const;

private:
	Graphics();
	Graphics(const Graphics & x) = delete;
	Graphics operator=(const Graphics & x) = delete;
	static Graphics* instance;
	std::vector <sf::Texture> m_pictures;
	sf::Font m_font;
	// std::vector <sf::Sound> m_sounds;
	// sf::Music m_music;
};

