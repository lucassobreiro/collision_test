#include "collision.hpp"

void Collision::update(float r1pX, float r1pY, float r1sX, float r1sY,
float r2pX, float r2pY, float r2sX, float r2sY)
{
	r1_posX = r1pX;
	r1_posY = r1pY;
	r1_sizeX = r1sX;
	r1_sizeY = r1sY;
	
	r2_posX = r2pX;
	r2_posY = r2pY;
	r2_sizeX = r2sX;
	r2_sizeY = r2sY;
}

bool Collision::simple(sf::RectangleShape rec1, sf::RectangleShape rec2)
{
	update(rec1.getPosition().x, rec1.getPosition().y, rec1.getSize().x, rec1.getSize().y,
	rec2.getPosition().x, rec2.getPosition().y, rec2.getSize().x, rec2.getSize().y);

	if(r1_posX + r1_sizeX > r2_posX
	&& r1_posX < r2_posX + r2_sizeX
	&& r1_posY + r1_sizeY > r2_posY
	&& r1_posY < r2_posY + r2_sizeY)
		return true;
	else
		return false;
}

bool Collision::teleport(sf::RectangleShape* rec1, sf::RectangleShape rec2)
{	
	update(rec1->getPosition().x, rec1->getPosition().y, rec1->getSize().x, rec1->getSize().y,
	rec2.getPosition().x, rec2.getPosition().y, rec2.getSize().x, rec2.getSize().y);

	if(r1_posX < r2_posX
	&& r1_posY + r1_sizeY > r2_posY + 10
	&& r1_posY < r2_posY + r2_sizeY - 10
	&& r1_posX + r1_sizeX > r2_posX)
	{
		rec1->setPosition(sf::Vector2f(r2_posX - r1_sizeX, r1_posY));
		return true;
	}

	else if(r1_posX > r2_posX + r2_sizeX - r1_sizeX
	&& r1_posY + r1_sizeY > r2_posY + 10
	&& r1_posY < r2_posY + r2_sizeY - 10
	&& r1_posX < r2_posX + r2_sizeX)
	{
		rec1->setPosition(sf::Vector2f(r2_posX + r2_sizeX, r1_posY));
		return true;
	}

	else if(r1_posY < r2_posY
	&& r1_posX + r1_sizeX > r2_posX
	&& r1_posX < r2_posX + r2_sizeX
	&& r1_posY + r1_sizeY > r2_posY)
	{
		rec1->setPosition(sf::Vector2f(r1_posX, r2_posY - r1_sizeY));
		return true;
	}	

	else if(r1_posY > r2_posY + r2_sizeY - r1_sizeY
	&& r1_posX + r1_sizeX > r2_posX
	&& r1_posX < r2_posX + r2_sizeX
	&& r1_posY < r2_posY + r2_sizeY)
	{
		rec1->setPosition(sf::Vector2f(r1_posX, r2_posY + r2_sizeY));
		return true;
	}

	else
		return false;
}
