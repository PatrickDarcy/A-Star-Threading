#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class Enemy
{
private:
	sf::RectangleShape m_enemyShape;
	Grid* m_grid;
	std::vector<Node*> m_path;
	int m_delay;
	const int m_delayTime = 6000;
	float m_moveTime = 0;
	Node* m_enemyNode;
	Player* m_player;

public:
	Enemy(float t_enemySize, Node* t_enemyNode, Grid* t_grid, Player* t_player);
	void Update(sf::Time dt);
	void Render(sf::RenderWindow& t_window);
	void SetPos(sf::Vector2f t_pos);
	sf::Vector2f GetPos();
	void MoveToPlayer();
	Node* GetEnemyNode() { return m_enemyNode; };
	void SetPath(std::vector<Node*> t_path);
};


