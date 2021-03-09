#include "../include/Game.h"

#include "../include/Game.h"

Game::Game()
{
	RW = new sf::RenderWindow(sf::VideoMode(800, 600), "Title");

	while (RW->isOpen())
	{
		if (RW->pollEvent(mainEvent))
		{
			if (mainEvent.type == sf::Event::Closed | sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				RW->close();
		}

		RW->clear(sf::Color::Black);
		RW->display();
	}
}
Game::~Game()
{
	delete RW;
}