#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class Enemy
{
private:
	sf::RectangleShape m_enemyShape;
	Grid* m_grid;
	Player* m_player;
	std::vector<Node*> m_path;
	int m_delay;
	const int m_delayTime = 6000;
	float m_moveTime = 0;

public:
	Enemy(float t_enemySize, sf::Vector2i t_enemyPos, Grid* t_grid, Player* t_player);
	void Update(double dt);
	void Render(sf::RenderWindow& t_window);
	void SetPos(sf::Vector2f t_pos);
	sf::Vector2f GetPos();
	void MoveToPlayer();
};


