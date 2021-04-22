#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class Enemy
{
private:
	sf::RectangleShape m_enemyShape;

public:
	Enemy(float t_enemySize, sf::Vector2i t_enemyPos);
	void update(double dt);
	void render(sf::RenderWindow& t_window);
	void setPos(sf::Vector2f t_pos);
	sf::Vector2f getPos();
};


