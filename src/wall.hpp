#ifndef WALL_HPP
#define WALL_HPP

#include "app.hpp"

class Wall
{
private:
	const int size_min = 32;
	const int size_max = 512;
	
	const int speed_min = 1;
	const int speed_max = 8;
	
	int speedX, speedY;
	sf::RectangleShape rec;

public:
	void initWall(int color_r, int color_g, int color_b);
	void movement();
	
	//getters
	sf::RectangleShape getRec();
};

class Water: public Wall
{

};

#endif
