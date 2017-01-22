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
#include "Bullet.hpp"
#include "key.h"
#define _WIN32_WINNT 0x0500 
#include <windows.h> 
#include <iostream> 

sf::RectangleShape createRect(int x, int y, int sx, int sy)
{
	sf::RectangleShape rect(sf::Vector2f(sx, sy));
	rect.setPosition(x, y);
	return rect;
}

void restart(Player *player1, Player *player2)
{
	player1->relife();
	player2->relife();
}

int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, HIDE_WINDOW);
	int i;
	sf::Clock deltaClock;
	sf::Texture wall;
	sf::Texture tPlayer1;
	sf::Texture tPlayer2;
	sf::Texture onde1;
	sf::Texture onde2;
	sf::Texture end1;
	sf::Texture end2;
	sf::Texture cmd;
	sf::Texture tstart;
	sf::Sprite bg;
	sf::Sprite sEnd;
	sf::Sprite s1;
	sf::Sprite s2;
	sf::Sprite scmd;
	sf::Sprite sStart;
	sf::Event event;
	Key key;
	Bullet *bullet = new Bullet();
	if (!wall.loadFromFile("./ressources/textures/wall.png"))
		std::cout << "non" << std::endl;
	if (!tPlayer1.loadFromFile("./ressources/textures/player1.png"))
		std::cout << "non" << std::endl;
	if (!tPlayer2.loadFromFile("./ressources/textures/player2.png"))
		std::cout << "non" << std::endl;
	if (!onde1.loadFromFile("./ressources/textures/onde1.png"))
		std::cout << "non" << std::endl;
	if (!onde2.loadFromFile("./ressources/textures/onde2.png"))
		std::cout << "non" << std::endl;
	if (!end1.loadFromFile("./ressources/textures/end1.png"))
		std::cout << "non" << std::endl;
	if (!end2.loadFromFile("./ressources/textures/end2.png"))
		std::cout << "non" << std::endl;
	if (!cmd.loadFromFile("./ressources/textures/cmd.png"))
		std::cout << "non" << std::endl;
	if (!tstart.loadFromFile("./ressources/textures/start.png"))
		std::cout << "non" << std::endl;
	scmd.setTexture(cmd);
	sStart.setTexture(tstart);
	s1.setTexture(tPlayer1);
	s2.setTexture(tPlayer2);
	s2.scale(-1, 1);
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
	plateform.push_back(createRect(0, 270, 100, 30));
	plateform.push_back(createRect(924, 270, 100, 30));
	std::cout << plateform[0].getGlobalBounds().intersects(s1.getGlobalBounds()) << std::endl;
	window.setKeyRepeatEnabled(false);
	key.keyup1 = false;
	key.keyup1 = false;
	key.keydown1 = false;
	key.keydown2 = false;
	key.keyleft1 = false;
	key.keyleft2 = false;
	key.keyright1 = false;
	key.keyright2 = false;
	bool end = false;
	bool start = true;
	while (window.isOpen())
	{
		sf::Time dt = deltaClock.restart();
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
				if (event.key.code == sf::Keyboard::Escape)
					return 1;
				if (!end && !start)
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
					if (event.key.code == sf::Keyboard::Z)
						key.keyjump1 = true;
					if (event.key.code == sf::Keyboard::Up)
						key.keyjump2 = true;
					if (event.key.code == sf::Keyboard::F)
						key.keyfire1 = true;
					if (event.key.code == sf::Keyboard::RControl)
						key.keyfire2 = true;
				}
				else if (event.key.code == sf::Keyboard::R && !start)
				{
					player1.relife();
					player2.relife();
					bullet->del();
					end = false;
				}
				else if (event.key.code == sf::Keyboard::R && start)
				{
					start = false;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (!end && !start)
				{
					if (event.key.code == sf::Keyboard::Z)
						key.keyup1 = false;
					if (event.key.code == sf::Keyboard::Up)
						key.keyup1 = false;
					if (event.key.code == sf::Keyboard::S)
						key.keydown1 = false;
					if (event.key.code == sf::Keyboard::Down)
						key.keydown2 = false;
					if (event.key.code == sf::Keyboard::Q)
						key.keyleft1 = false;
					if (event.key.code == sf::Keyboard::Left)
						key.keyleft2 = false;
					if (event.key.code == sf::Keyboard::D)
						key.keyright1 = false;
					if (event.key.code == sf::Keyboard::Right)
						key.keyright2 = false;
				}
			}
		}
		if (key.keyfire1)
			bullet->add(1, player1, &onde1);
		if (key.keyfire2)
			bullet->add(2, player2, &onde2);
		player1.update(key, dt.asSeconds(), plateform);
		player2.update(key, dt.asSeconds(), plateform);
		if (bullet->update(plateform, &player1, &player2, dt.asSeconds()))
		{
			if (player1.life <= 0)
				sEnd.setTexture(end2);
			if (player2.life <= 0)
				sEnd.setTexture(end1);
			bullet->del();
			end = true;
		}
		window.clear(sf::Color(200, 200, 200));
		window.draw(bg);
		i = 0;
		while (i < plateform.size())
			window.draw(plateform[i++]);
		bullet->draw(&window);
		window.draw(*player1.getSprite());
		window.draw(*player2.getSprite());
		window.draw(scmd);
		if (end)
			window.draw(sEnd);
		if (start)
			window.draw(sStart);
		window.display();
	}

    return EXIT_SUCCESS;
}

 
