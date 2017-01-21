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
public:
	Player(int ID, sf::Sprite *_sprite) {
		this->ID = ID;
		this->life = 4;
		this->posX = 50 * ID;
		this->posY = 600;
		sprite = _sprite;
		sprite->setPosition(posX, posY);
	}
	~Player() {
	}
	sf::Sprite *getSprite() {
		return sprite;
	}
	void update(Key key);
	int posX;
	int posY;
	int life;
	int ID;
	sf::Sprite *sprite;
private:

};

#endif // !PLAYER_HPP
