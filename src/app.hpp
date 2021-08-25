#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

#include "player.hpp"
#include "collision.hpp"
#include "wall.hpp"

//screen size
#define W_WIDTH 1280
#define W_HEIGHT 720

//map density
#define WALL_LIMIT 1000
#define WATER_LIMIT 250

class App
{
private:
	bool wallMovement = false;	

	sf::RenderWindow window;
	sf::Event event;
	sf::View view;

public:
	void initApp(bool restart);
	void update();

};

#endif
