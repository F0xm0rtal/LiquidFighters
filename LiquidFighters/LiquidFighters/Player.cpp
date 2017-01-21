#include "stdafx.h"
#include "player.hpp"

void Player::update(Key key)
{
	int i = 0;

	if ((ID == 1 && key.keyright1) || (ID == 2 && key.keyright2))
		posX += 1;
	if ((ID == 1 && key.keyleft1) || (ID == 2 && key.keyleft2))
		posX -= 1;
	if ((ID == 1 && key.keyjump1) || (ID == 2 && key.keyjump2))
	{
		while (i != 20)
		{
			posY += 1;
			i += 1;
		}
	}
		
	sprite->setPosition(posX, posY);
}