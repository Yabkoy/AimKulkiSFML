#pragma once
#include "libs.h"

class Game
{
private:
	sf::RenderWindow* RW; 
	sf::Event mainEvent;

	void update();

	void initObjects();

public:
	Game();

	~Game();
};