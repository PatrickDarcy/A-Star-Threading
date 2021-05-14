#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <cmath>

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
	int m_pathCost = INT_MAX;
	float m_heuristic;
	bool m_marked;
	int m_index;
	Node* m_previous;
	std::vector<Node*>* m_neighbours = new std::vector<Node*>;
};

