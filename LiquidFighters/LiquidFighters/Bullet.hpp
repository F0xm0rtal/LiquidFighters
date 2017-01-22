#ifndef BULLET_HPP_
#define BULLET_HPP_

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "player.hpp"

class Bullet
{
public:
	Bullet()
		: t1(0), t2(0)
	{}
	~Bullet() {}
	typedef struct s_ball
	{
		float x;
		float y;
		int id;
		int view;
		sf::Sprite s;
	} Ball;

	bool update(std::vector<sf::RectangleShape> plateform, Player *player1, Player *player2, float dt)
	{
		int i = 0;
		if (t1 < 0)
			t1 = 0;
		else if (t1 > 0)
			t1 -= 5 * dt;
		if (t2 < 0)
			t2 = 0;
		else if (t2 > 0)
			t2 -= 5 * dt;
		while (i < balls.size())
		{
			if (balls[i].view)
				balls[i].x += 5;
			else
				balls[i].x -= 5;
			balls[i].s.setPosition(balls[i].x, balls[i].y);
			if (checkCollision(plateform, i))
				balls.erase(balls.begin() + i);
			else if (balls[i].id == 1 && balls[i].s.getGlobalBounds().intersects(player2->sprite->getGlobalBounds()))
				player2->ou();
			else if (balls[i].id == 2 && balls[i].s.getGlobalBounds().intersects(player1->sprite->getGlobalBounds()))
				player1->ou();
			if (player1->life <= 0)
				return true;
			if (player2->life <= 0)
				return true;
			i++;
		}
		return false;
	}
	bool checkCollision(std::vector<sf::RectangleShape> plateform, int n)
	{
		int i = 0;

		while (i < plateform.size())
		{
			if (plateform[i].getGlobalBounds().intersects(balls[n].s.getGlobalBounds()))
				return true;
			i++;
		}
		return false;
	}
	void add(int _id, Player player, sf::Texture *texture)
	{
		if ((_id == 1 && t1 > 0) || (_id == 2 && t2 > 0))
			return;
		else if (_id == 1)
			t1 = 5;
		else
			t2 = 5;
		Ball ball;
		ball.id = player.ID;
		ball.view = player.view;
		ball.s.setTexture(*texture);
		if (ball.view)
		{
			ball.x = player.posX;
			ball.y = player.posY+ 30;
		}
		else
		{
			ball.x = player.posX - 25;
			ball.y = player.posY + 25;
		}
		ball.s.setPosition(ball.x, ball.y);
		balls.push_back(ball);
	}
	void draw(sf::RenderWindow *win)
	{
		int i = 0;
		while (i < balls.size())
		{
			win->draw(balls[i].s);
			i++;
		}
	}
	void del()
	{
		while (balls.size() > 0)
		{
			balls.erase(balls.begin());
		}
	}
	std::vector<Ball> balls;
	float t1;
	float t2;
};

#endif