#include "../include/Game.h"

Game::Game()
{
	RW = new sf::RenderWindow(sf::VideoMode(WIN_W, WIN_H), "Title");
	update();
}

Game::~Game()
{
	delete RW;
}

void Game::initObjects()
{

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

		//for (sf::Shape* : )
		//{

		//}

		RW->display();
	}
}