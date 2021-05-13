#pragma once
#include <SFML/Graphics.hpp>
#include <map>

enum NodeType
{
	EMPTY,
	OCCUPIED,
	WALL
};

struct Node
{
	sf::Vector2f m_pos;
	NodeType m_nodeType = NodeType::EMPTY;
	int m_pathCost;
	float m_heuristic;
	int m_index;
	std::vector<Node*>* m_neighbour;
};

