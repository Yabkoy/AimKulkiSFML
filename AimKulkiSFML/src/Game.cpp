#include "../include/Game.h"

Game::Game()
{
	RW = new sf::RenderWindow(sf::VideoMode(WIN_W, WIN_H), "Title"); //Creating Window and allocating SFML RenderWindow
	mainShapesPointer.reserve(2);
	mainShapesPointer.emplace_back(&yourCharacter);
	mainShapesPointer.emplace_back(&enemyCharacter);

	initObjects(); // initialization Shapes Objects and add arguments

	update(); //start to execute update function
}

Game::~Game()
{
	delete RW; //Delete RenderWindow from memory
}

void Game::initObjects()
{
	for (sf::Shape* curretObejct : mainShapesPointer)
	{
		sf::CircleShape* castObject = (sf::CircleShape*)curretObejct;
		castObject->setRadius(mainRadius);
		castObject->setPointCount(30);
		castObject->setOrigin(sf::Vector2f(mainRadius, mainRadius));
		castObject->setFillColor(sf::Color::Red);
		castObject->setPosition(sf::Vector2f(WIN_W / 2, WIN_H / 2));
	}
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

		for (sf::Shape* curretObejct : mainShapesPointer) //drawing object loop
		{
			RW->draw(*curretObejct);
		}


		RW->display(); //Displaying RenderWindow;
	}
}