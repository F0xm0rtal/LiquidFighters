#pragma once

#ifndef PLAYER_HPP
# define PALYER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "key.h"

class Player
{
	typedef struct s_vector2d
	{
		float x;
		float y;
	} Vector2d;
public:
	Player(int ID, sf::Sprite *_sprite) {
		this->ID = ID;
		this->life = 4;
		if (ID == 1)
		{
			this->posX = 30;
			this->posY = 250 - 88;
		}
		if (ID == 2)
		{
			this->posX = 1024 - 30 - 110;
			this->posY = 250 - 88;
		}
		V.x = 0;
		V.y = 0;
		sprite = _sprite;
		jumpSpeed = 400;
		speed = 200;
		if (ID == 1)
			view = true;
		else
		{
			posX += 88;
			view = false;
		}
		sprite->setPosition(posX, posY);
	}
	~Player() {
	}
	sf::Sprite *getSprite() {
		return sprite;
	}
	void update(Key key, float dt, std::vector<sf::RectangleShape> plateform);
	bool checkCollision(std::vector<sf::RectangleShape> plateform);
	bool checkCollisionDown(std::vector<sf::RectangleShape> plateform);
	void ou()
	{
		life -= 1;
		if (life <= 0)
			return;
		if (ID == 1)
		{
			this->posX = 30;
			this->posY = 250 - 88;
		}
		if (ID == 2)
		{
			this->posX = 1024 - 30 - 110;
			this->posY = 250 - 88;
		}
		V.x = 0;
		V.y = 0;
		if (ID == 1)
		{
			if (!view)
				sprite->scale(-1, 1);
			view = true;
		}
		else
		{
			if (view)
				sprite->scale(-1, 1);
			posX += 88;
			view = false;
		}
		sprite->setPosition(posX, posY);
	}
	void relife()
	{

		if (ID == 1)
		{
			this->posX = 30;
			this->posY = 250 - 88;
		}
		if (ID == 2)
		{
			this->posX = 1024 - 30 - 110;
			this->posY = 250 - 88;
		}
		V.x = 0;
		V.y = 0;
		life = 4;
		if (ID == 1)
			view = true;
		else
		{
			posX += 88;
			view = false;
		}
		sprite->setPosition(posX, posY);
	}
	float posX;
	float posY;
	int life;
	Vector2d V;
	int ID;
	sf::Sprite *sprite;
	int jumpSpeed;
	int speed;
	bool view;
private:

};

#endif // !PLAYER_HPP
