#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphNode.h"
#include "NodeData.h"
#include "Map.h"
#include "Player.h"

typedef GraphNode<NodeData, int> Node;

class Enemy
{
private:
	sf::Vector2f m_pos;
	sf::RectangleShape m_enemy;
	//Direction m_dir;
	double m_findPlayerTime = 0;
	float m_moveTime = 0;
	const float m_scale = 50.0f;
	Map* m_map;
	Player* m_player;
	GraphNode<NodeData,int>* m_playerCurrentNode;
	sf::Vector2i m_enemyIndex = {5,6};
	std::vector<Node*> m_path;
	float m_enemyMoveDelay;
	int m_delay;
	const int m_delayTime = 6000;
	const int m_rowColSize = 20;
	sf::Clock m_animationClock;

public:
	Enemy();
	void initEnemy();
	void animateSprite();
	void update(double dt);
	void render(sf::RenderWindow& t_window);
	void setMapPointer(Map* t_map);
	void setPlayer(Player* t_player);
	void moveToPlayer();

};


