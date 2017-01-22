#include "stdafx.h"
#include "player.hpp"

bool Player::checkCollision(std::vector<sf::RectangleShape> plateform)
{
	int i = 0;

	while (i < plateform.size())
	{
		if (plateform[i].getGlobalBounds().intersects(sprite->getGlobalBounds()))
			return true;
		i++;
	}
	return false;
}

bool Player::checkCollisionDown(std::vector<sf::RectangleShape> plateform)
{
	int i = 0;
	sf::RectangleShape rect(sf::Vector2f(88, 4));
	rect.setPosition(posX, posY + 82);

	while (i < plateform.size())
	{
		if (plateform[i].getGlobalBounds().intersects(rect.getGlobalBounds()))
			return true;
		i++;
	}
	return false;
}

void Player::update(Key key, float dt, std::vector<sf::RectangleShape> plateform)
{
	int i = 0;
	float _posX = posX;
	float _posY = posY;

	if ((ID == 1 && key.keyright1) || (ID == 2 && key.keyright2))
	{
		if (view == false)
		{
			posX -= 88;
			_posX -= 88;
			sprite->scale(-1, 1);
		}
		view = true;
		V.x = speed;
	}
	else if ((ID == 1 && key.keyleft1) || (ID == 2 && key.keyleft2))
	{
		if (view == true)
		{
			posX += 88;
			_posX += 88;
			sprite->scale(-1, 1);
		}
		view = false;
		V.x = -speed;
	}
	else
	{
		if (V.x > 0)
			V.x -= speed * 3 * dt;
		if (V.x < 0)
			V.x += speed * 3 * dt;
		if (abs(V.x) < 10)
			V.x = 0;
	}
	if (((ID == 1 && key.keyjump1) || (ID == 2 && key.keyjump2)) && checkCollisionDown(plateform))
	{
		V.y = jumpSpeed;
	}
	else
	{
		V.y -= jumpSpeed * dt;
		if (V.y < -jumpSpeed)
			V.y = -jumpSpeed;
	}
	posY -= V.y * dt;
	posX += V.x * dt;

	sprite->setPosition(_posX, posY);
	if (checkCollision(plateform) || (posY < 30 || posY >= (738 - 82)))
	{
		posY = _posY;
		sprite->setPosition(_posX, posY);
		V.y = 0;
	}
	sprite->setPosition(posX, posY);
	if (checkCollision(plateform))
	{
		posX = _posX;
		sprite->setPosition(posX, posY);
		V.x = 0;
	}
}