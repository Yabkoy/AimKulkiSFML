#include "../include/Game.h"

Game::Game()
{
	RW = new sf::RenderWindow(sf::VideoMode(800, 600), "Title");
}
Game::~Game()
{
	delete RW;
}

void Game::update()
{
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