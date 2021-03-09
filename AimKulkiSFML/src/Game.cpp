#include "../include/Game.h"

Game::Game()
{
	RW = new sf::RenderWindow(sf::VideoMode(WIN_W, WIN_H), "Title"); //Creating Window and allocating SFML RenderWindow
	

	update(); //start to execute update function
}

Game::~Game()
{
	delete RW; //Delete RenderWindow from memory
}

void Game::initObjects()
{

}

void Game::update()
{
	while (RW->isOpen()) //Main Game loop
	{
		if (RW->pollEvent(mainEvent))
		{
			if (mainEvent.type == sf::Event::Closed | sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				RW->close();
		}
		RW->clear(sf::Color::Black); //Clearing background to Black

		//for (sf::Shape* : )
		//{

		//}

		RW->display(); //Displaying RenderWindow;
	}
}