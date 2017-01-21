#pragma once

#ifndef PLAYER_HPP
# define PALYER_HPP

# include <iostream>

class Player
{
public:
	Player(int ID);
	~Player();
	int posX;
	int posY;
	int life;
	int ID;
private:

};

Player::Player(int ID)
{
	this->ID = ID;
	this->life = 100;
	this->posX = 50 * ID;
	this->posY = 10;
}

Player::~Player()
{
	std::cout << "AAAARRRGH!!!" << std::endl;
}

#endif // !PLAYER_HPP
