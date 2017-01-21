#include "stdafx.h"
#include "player.hpp"

void Player::update(Key key)
{
	if ((ID == 1 && key.keyright1) || (ID == 2 && key.keyright2))
		posX += 1;
	if ((ID == 1 && key.keyleft1) || (ID == 2 && key.keyleft2))
		posX -= 1;
	sprite->setPosition(posX, posY);
}