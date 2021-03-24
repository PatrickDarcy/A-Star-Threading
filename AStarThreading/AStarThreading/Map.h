#pragma once
#include"Graph.h"
#include"NodeData.h"
#include"GraphArc.h"
#include"GraphNode.h"
#include"SFML/Graphics.hpp"
#include<fstream>

class Map
{
private:
	Graph<NodeData, int> nodeMap;
	NodeData m_nodeData;
	int from, to, weight;
	int m_row;
	int m_col;
	int m_numOfNodes;

public:
	int m_tileIndex = 0;
	Map(int t_mapSize, int t_row, int t_col);
	void initMap();
	void update();
	void setUpArcs();
	void addTileNode(NodeData t_node);
	void draw(sf::RenderWindow& t_window);
	GraphNode<NodeData, int>* getNode(sf::Vector2i t_index);
	Graph<NodeData, int> & getGraph();
	sf::Vector2i getRowCol() { return sf::Vector2i{ m_row, m_col }; };
}; 