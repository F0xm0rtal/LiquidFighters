// LiquidFighters.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
=======
#include "Player.hpp"
>>>>>>> 35c7e561b7d821a7bd83fbadec9be52652a506e8

sf::RectangleShape createRect(int x, int y, int sx, int sy, sf::Texture texture)
{
	sf::RectangleShape rect(sf::Vector2f(sx, sy));
	rect.setPosition(x, y);
	//rect.setTexture(&texture);
	return rect;
}

int main()
{
	int i;
	sf::Texture brick;
	if (!brick.loadFromFile(".\brick.png"))
	{
		std::cout << "test" << std::endl;
	}
	std::vector<sf::RectangleShape> plateform;
	sf::RenderWindow window(sf::VideoMode(1024, 768), "LiquidFihters");
	//512, 385       , 205
	plateform.push_back(createRect(0, 738, 1024, 30, brick));
	plateform.push_back(createRect(0, 0, 1024, 30, brick));
	plateform.push_back(createRect(994, 0, 30, 768, brick));
	plateform.push_back(createRect(0, 0, 30, 768, brick));
	plateform.push_back(createRect(232, 150, 560, 30, brick));
	plateform.push_back(createRect(362, 300, 300, 30, brick));
	plateform.push_back(createRect(232, 150, 30, 200, brick));
	plateform.push_back(createRect(762, 150, 30, 200, brick));
	plateform.push_back(createRect(150, 450, 230, 30, brick));
	plateform.push_back(createRect(644, 450, 230, 30, brick));
	plateform.push_back(createRect(437, 570, 150, 30, brick));
	plateform.push_back(createRect(0, 600, 150, 30, brick));
	plateform.push_back(createRect(874, 600, 150, 30, brick));
	plateform.push_back(createRect(0, 270, 150, 30, brick));
	plateform.push_back(createRect(874, 270, 150, 30, brick));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

<<<<<<< HEAD
		window.clear(sf::Color(200, 200, 200));
		i = 0;
		while (i < plateform.size())
			window.draw(plateform[i++]);
=======
		window.clear();
>>>>>>> 35c7e561b7d821a7bd83fbadec9be52652a506e8
		window.display();
	}

    return EXIT_SUCCESS;
}

 
