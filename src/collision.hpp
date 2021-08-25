#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "app.hpp"

class Collision
{
private:
	float r1_posX;
	float r1_posY;
	float r1_sizeX;
	float r1_sizeY;
	
	float r2_posX;
	float r2_posY;
	float r2_sizeX;
	float r2_sizeY;

	void update(float r1pX, float r1pY, float r1sX, float r1sY, 
	float r2pX, float r2pY, float r2sX, float r2sY);

public:	
	bool simple(sf::RectangleShape rec1, sf::RectangleShape rec2);
	bool teleport(sf::RectangleShape* rec1, sf::RectangleShape rec2);

};

#endif
