#pragma once
#include  <string>
#include "GraphNode.h"
#include <map>
#include <SFML/Graphics.hpp>

// ---------------------------------------------------------------------
//  Name:           NodeData
//  Description:    A simple struct to encapsulate all the node data.
//                  Add or remove fields as required.               
// ---------------------------------------------------------------------
//template<class NodeType, class ArcType>
//typedef GraphNode<NodeType, ArcType> Node;

struct NodeData
{
	sf::RectangleShape m_cube;
	int m_type;
	int m_pathCost;
	float m_heuristic;
	int m_index;
	float m_positionX;
	float m_positionY;
	int m_numberOfItems;
	std::map<std::string, GraphNode<NodeData, int>*> m_neighbours;
};
