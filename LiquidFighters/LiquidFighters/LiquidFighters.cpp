// LiquidFighters.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(840, 420), "LiquidFihters");

//	sf::Music music;
//	if (!music.openFromFile("nice_music.ogg"))
//		return EXIT_FAILURE;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

    return EXIT_SUCCESS;
}

