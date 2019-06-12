#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::openingScreen(sf::RenderWindow & window)
{
	sf::RectangleShape playButton;
	sf::Text playText;
	sf::Vector2f mousePosition;
	sf::RectangleShape backgroundStart;

	backgroundStart.setSize({ (float)window.getSize().x, (float)window.getSize().y});
	backgroundStart.setPosition({ 0,0 });

	window.clear();
	backgroundStart.setTexture(Graphics::getInstance().getTexture(9));
	window.draw(backgroundStart);


	playButton.setFillColor(sf::Color::Transparent);
	playButton.setPosition({ 0, 0 });
	playButton.setSize({ 150, 70 });

	playText.setPosition(playButton.getPosition());
	playText.setCharacterSize(50);
	playText.setFont(* Graphics::getInstance().getFont());
	playText.setFillColor(sf::Color::White);
	playText.setString("Play");

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
	}
// background.setTexture(graphics.getTexture(12));
}