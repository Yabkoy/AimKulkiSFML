#include "../include/Game.h"

Game::Game()
{
	RW = new sf::RenderWindow(sf::VideoMode(WIN_W, WIN_H), "AddectiveGame"); //Creating Window and allocating SFML RenderWindow
	mainShapesPointer.reserve(2);
	mainShapesPointer.emplace_back(&yourCharacter);
	mainShapesPointer.emplace_back(&enemyCharacter);

	initObjects(); // initialization Shapes Objects and add arguments
	// mainFont.loadFromFile("mainFont.otf");
	update(); //start to execute update function
}

Game::~Game()
{
	delete RW; //Delete RenderWindow obejct from memory
}

void Game::initObjects()
{
	mainPoints = 0;

	for (sf::Shape* curretObejct : mainShapesPointer)
	{
		sf::CircleShape* castObject = (sf::CircleShape*)curretObejct;
		castObject->setRadius(mainRadius);
		castObject->setPointCount(30);
		castObject->setOrigin(sf::Vector2f(mainRadius, mainRadius));
		castObject->setFillColor(sf::Color::Red);
		castObject->setPosition(sf::Vector2f(WIN_W / 2, WIN_H / 2));
	}
	yourCharacter.setOutlineThickness(5);
	yourCharacter.setOutlineColor(sf::Color::White);


}

void Game::update()
{
	while (RW->isOpen()) //Main Game loop
	{
		if (RW->pollEvent(mainEvent)) // Poll Event
		{
			if (mainEvent.type == sf::Event::Closed | sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				RW->close();
		}
		RW->clear(sf::Color::Black); //Clearing background to Black


		if (yourCharacter.getGlobalBounds().contains(sf::Mouse::getPosition(*RW).x, sf::Mouse::getPosition(*RW).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) //On Mouse pressed - obejct move
			yourCharacter.setPosition(sf::Vector2f(sf::Mouse::getPosition(*RW).x, sf::Mouse::getPosition(*RW).y)); 

		if (yourCharacter.getGlobalBounds().intersects(enemyCharacter.getGlobalBounds())) //Enemy collision detection
		{
			yourCharacter.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			enemyCharacter.setPosition(sf::Vector2f(rand() % WIN_W, rand() % WIN_H));
			enemyCharacter.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			mainPoints++;
			pointsText.setString(mainPoints);
		}
			
		for (sf::Shape* curretObejct : mainShapesPointer) //drawing object loop
		{
			RW->draw(*curretObejct);
		}
		RW->draw(pointsText);


		RW->display(); //Displaying RenderWindow;
	}
}