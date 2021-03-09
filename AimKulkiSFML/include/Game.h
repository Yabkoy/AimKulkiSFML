#pragma once
#include "libs.h"

class Game
{
private: //Window Initialization
	sf::RenderWindow* RW; 
	sf::Event mainEvent;
private: //Game Objects
		
private: //Private Functions
	void update();

	void initObjects();

public: //Game Constructor and Destructor
	Game();
	~Game();
};