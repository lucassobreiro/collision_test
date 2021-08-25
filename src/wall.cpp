#include "wall.hpp"

void Wall::initWall(int color_r, int color_g, int color_b)
{
	rec.setSize(sf::Vector2f((rand()%size_max)+size_min, (rand()%size_max)+size_min));
	rec.setPosition(sf::Vector2f(rand()%20000, rand()%20000));
	rec.setFillColor(sf::Color(color_r, color_g, color_b));

	speedX = (rand()%speed_max) + speed_min;
	speedY = (rand()%speed_max) + speed_min;
}

void Wall::movement()
{
	rec.move(speedX, speedY);
}

//getters
sf::RectangleShape Wall::getRec()
{
	return rec;
}

