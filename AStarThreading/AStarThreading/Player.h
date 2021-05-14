#pragma once
#include "SFML/Graphics.hpp"
#include "Node.h"
#include "Grid.h"

class Player
{
private:
	sf::RectangleShape m_player;
	Node* m_playerNode;

public:
	Player() {};
	Player(Node* t_playerNode);
	~Player();
	sf::Vector2f GetPlayerPos();
	Node* GetPlayerNode();
};

