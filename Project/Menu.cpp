#include "Menu.h"

#include <Windows.h>


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::transitionalScreen(sf::RenderWindow & window, string text, int index)
{
	// Transitional screens between levels
	Graphics::getInstance().getMusic()->play();
	sf::RectangleShape playButton;
	sf::Text playText;
	sf::Vector2f mousePosition;
	sf::RectangleShape backgroundStart;

	backgroundStart.setSize({ (float)window.getSize().x, (float)window.getSize().y});
	backgroundStart.setPosition({ 0,0 });

	window.clear();
	backgroundStart.setTexture(Graphics::getInstance().getTexture(index));
	window.draw(backgroundStart);


	playButton.setFillColor(sf::Color::Transparent);
	playButton.setPosition({(float)(window.getSize().x /2) - 150, (float)(window.getSize().y / 2)  + 200});
	playButton.setSize({ 350, 200 });

	playText.setPosition(playButton.getPosition());
	playText.setCharacterSize(100);
	playText.setFont(* Graphics::getInstance().getFont());
	playText.setFillColor(sf::Color::White);
	playText.setString(text);

	window.draw(playButton);
	window.draw(playText);

	window.display();


	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				mousePosition = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				if (playButton.getGlobalBounds().contains(mousePosition))
					break;
			}
		if (event.type == sf::Event::Closed)
		{
			window.close();
			exit(EXIT_SUCCESS);
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
				break;
			}
		}
	}
	Graphics::getInstance().getMusic()->setVolume(20);
	// Graphics::getInstance().stopMusic();
// background.setTexture(graphics.getTexture(12));
}

void Menu::viewMap(sf::RenderWindow & window)
{
	// Shows the users current progress by showing the map
	int index = LevelManager::getInstance().getIndexLevel();
	sf::RectangleShape map;

	map.setSize({ (float)window.getSize().x, (float)window.getSize().y });

	window.clear();
	map.setTexture(Graphics::getInstance().getTexture(index + 11));
	window.draw(map);
	window.display();

	Sleep(3000);
	
}
