#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "app.hpp"

class Player
{
private:
	const int size = 32;
	float speed = 8.f;
	
	sf::RectangleShape rec;	

public:
	void initPlayer();
	void movement();
	void setColorToBlue(bool blue);
	
	//getters
	sf::RectangleShape getRec();
	sf::RectangleShape* getRecAddress();
	float getSpeed();
	
	//setters
	void setSpeed(float newSpeed);
};

#endif
