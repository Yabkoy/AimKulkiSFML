#pragma once
#include "libs.h"

class Game
{
private: //Window Initialization
	sf::RenderWindow* RW; 
	sf::Event mainEvent;
	std::vector<sf::Shape*> mainShapesPointer;
private: //Game Objects
	sf::CircleShape yourCharacter;
	sf::CircleShape enemyCharacter;

private: //Private Functions
	void update();

	void initObjects();

public: //Game Constructor and Destructor
	Game();
	~Game();
};