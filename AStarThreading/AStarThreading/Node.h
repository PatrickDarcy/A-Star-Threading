#pragma once
#include <SFML/Graphics.hpp>

enum NodeType
{
	EMPTY,
	OCCUPIED,
	WALL
};

class Node
{
private:
	sf::Vector2f m_pos;
	NodeType m_nodeType;
public:
	Node(sf::Vector2f t_pos, NodeType t_nodeType);
	~Node();
};

