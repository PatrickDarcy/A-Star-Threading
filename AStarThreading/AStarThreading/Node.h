#pragma once
#include <SFML/Graphics.hpp>

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
	sf::Color m_color = sf::Color::Green;
};

