#pragma once
#include "libs.h"

class Game
{
private:
	sf::RenderWindow* RW; 
	sf::Event mainEvent;

	void update();

public:
	Game();

	~Game();

};