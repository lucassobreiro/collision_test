#include "player.hpp"

void Player::initPlayer()
{
	rec.setSize(sf::Vector2f(size, size));
	rec.setPosition(sf::Vector2f(10000, 10000));
	rec.setFillColor(sf::Color::Black);
}

void Player::movement()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) rec.move(-speed, 0);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) rec.move(speed, 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) rec.move(0, -speed);
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) rec.move(0, speed);
}

void Player::setColorToBlue(bool blue)
{
	if(blue)
		rec.setFillColor(sf::Color::Blue);
	else
		rec.setFillColor(sf::Color::Black);
}

//getters
sf::RectangleShape Player::getRec()
{
	return rec;
}

sf::RectangleShape* Player::getRecAddress()
{
	return &rec;
}

float Player::getSpeed()
{
	return speed;
}

//setters
void Player::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

