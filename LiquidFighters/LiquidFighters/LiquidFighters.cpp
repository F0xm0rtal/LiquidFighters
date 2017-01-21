// LiquidFighters.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Player.hpp"
#include "key.h"

sf::RectangleShape createRect(int x, int y, int sx, int sy)
{
	sf::RectangleShape rect(sf::Vector2f(sx, sy));
	rect.setPosition(x, y);
	return rect;
}

int main()
{
	int i;
	sf::Texture brick;
	sf::Texture wall;
	sf::Sprite bg;
	sf::Sprite s1;
	sf::Sprite s2;
	sf::Event event;
	Key key;
	if (!brick.loadFromFile("C:\\brick.png"))
		std::cout << "non" << std::endl;
	if (!wall.loadFromFile("C:\\wall.png"))
		std::cout << "non" << std::endl;
	s2.setTexture(brick);
	s1.setTexture(brick);
	Player player1(1, &s1);
	Player player2(2, &s2);
	bg.setTexture(wall);
	std::vector<sf::RectangleShape> plateform;
	sf::RenderWindow window(sf::VideoMode(1024, 768), "LiquidFihters");
	plateform.push_back(createRect(0, 738, 1024, 30));
	plateform.push_back(createRect(0, 0, 1024, 30));
	plateform.push_back(createRect(994, 0, 30, 768));
	plateform.push_back(createRect(0, 0, 30, 768));	
	plateform.push_back(createRect(232, 150, 560, 30));
	plateform.push_back(createRect(362, 300, 300, 30));
	plateform.push_back(createRect(232, 150, 30, 200));
	plateform.push_back(createRect(762, 150, 30, 200));
	plateform.push_back(createRect(150, 450, 230, 30));
	plateform.push_back(createRect(644, 450, 230, 30));
	plateform.push_back(createRect(437, 570, 150, 30));
	plateform.push_back(createRect(0, 600, 150, 30));
	plateform.push_back(createRect(874, 600, 150, 30));
	plateform.push_back(createRect(0, 270, 150, 30));
	plateform.push_back(createRect(874, 270, 150, 30));
	while (window.isOpen())
	{
		key.keyup1 = false;
		key.keyup1 = false;
		key.keydown1 = false;
		key.keydown2 = false;
		key.keyleft1 = false;
		key.keyleft2 = false;
		key.keyright1 = false;
		key.keyright2 = false;
		key.keyjump1 = false;
		key.keyjump2 = false;
		key.keyfire1 = false;
		key.keyfire2 = false;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Z)
					key.keyup1 = true;
				if (event.key.code == sf::Keyboard::Up)
					key.keyup1 = true;
				if (event.key.code == sf::Keyboard::S)
					key.keydown1 = true;
				if (event.key.code == sf::Keyboard::Down)
					key.keydown2 = true;
				if (event.key.code == sf::Keyboard::Q)
					key.keyleft1 = true;
				if (event.key.code == sf::Keyboard::Left)
					key.keyleft2 = true;
				if (event.key.code == sf::Keyboard::D)
					key.keyright1 = true;
				if (event.key.code == sf::Keyboard::Right)
					key.keyright2 = true;
				if (event.key.code == sf::Keyboard::F)
					key.keyjump1 = true;
				if (event.key.code == sf::Keyboard::RAlt)
					key.keyjump2 = true;
				if (event.key.code == sf::Keyboard::G)
					key.keyfire1 = true;
				if (event.key.code == sf::Keyboard::RControl)
					key.keyfire2 = true;
			}
		}
		player1.update(key);
		player2.update(key);
		window.clear(sf::Color(200, 200, 200));
		window.draw(bg);
		i = 0;
		while (i < plateform.size())
			window.draw(plateform[i++]);
		window.draw(*player1.getSprite());
		window.draw(*player2.getSprite());
		window.display();
	}

    return EXIT_SUCCESS;
}

 
