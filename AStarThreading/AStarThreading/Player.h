#pragma once
#include "SFML/Graphics.hpp"
#include "GraphNode.h"
#include "NodeData.h"

class Player
{
private:
	sf::RectangleShape m_player;
	GraphNode<NodeData, int>* m_currentNode;

public:
	Player();
	~Player();
	sf::Vector2f GetPlayerPos();
	GraphNode<NodeData, int>* GetCurrentNode();
};

