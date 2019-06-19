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
	sf::RectangleShape playButton;
	sf::RectangleShape helpButton;
	sf::Text playText;
	sf::Text helpText;
	sf::Vector2f mousePosition;
	sf::RectangleShape backgroundStart;
	sf::FloatRect textRect;

	backgroundStart.setSize({ (float)window.getSize().x, (float)window.getSize().y});
	backgroundStart.setPosition({ 0,0 });

	window.clear();
	backgroundStart.setTexture(Graphics::getInstance().getTexture(index));
	window.draw(backgroundStart);


	playButton.setFillColor(sf::Color::Transparent);
	playButton.setSize({ 285, 100 });
	playButton.setOrigin({ 129,50 });
	playButton.setPosition({(float)(window.getSize().x /2) , (float)(window.getSize().y / 2)  + 200});

	playText.setCharacterSize(100);
	playText.setFont(* Graphics::getInstance().getFont());
	playText.setFillColor(sf::Color::White);
	playText.setString(text);
	playText.setOutlineThickness(5);
	playText.setOutlineColor(sf::Color::Black);

	textRect = playText.getLocalBounds();
	playText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	playText.setPosition(playButton.getPosition());


	helpButton.setFillColor(sf::Color::Transparent);
	helpButton.setSize({ 295, 100 });
	helpButton.setOrigin({ 129,50 });
	helpButton.setPosition({ (float)(window.getSize().x / 2) , (float)(window.getSize().y / 2) + 350 });

	
	helpText.setCharacterSize(100);
	helpText.setFont(*Graphics::getInstance().getFont());
	helpText.setFillColor(sf::Color::White);
	helpText.setString("help");
	helpText.setOutlineThickness(5);
	helpText.setOutlineColor(sf::Color::Black);

	textRect = helpText.getLocalBounds();
	helpText.setOrigin(textRect.left + textRect.width /2 , textRect.top + textRect.height / 2);
	helpText.setPosition(helpButton.getPosition());



	window.draw(backgroundStart);
	window.draw(helpButton);
	window.draw(helpText);
	window.draw(playButton);
	window.draw(playText);
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				mousePosition = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });


				if (playButton.getGlobalBounds().contains(mousePosition) && !m_help)
					break;

				m_help = false;
				
				if (helpButton.getGlobalBounds().contains(mousePosition))
					m_help = true;

				if (m_help)
				{
					backgroundStart.setTexture(Graphics::getInstance().getTexture(23));
					window.draw(backgroundStart);
					window.display();
				}
				else
				{
					backgroundStart.setTexture(Graphics::getInstance().getTexture(index));
					window.draw(backgroundStart);
					window.draw(helpButton);
					window.draw(helpText);
					window.draw(playButton);
					window.draw(playText);
					window.display();
				}
			}
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
