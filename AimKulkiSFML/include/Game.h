#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow* RW; 
	sf::Event mainEvent;
public:
	Game();

	~Game();

};