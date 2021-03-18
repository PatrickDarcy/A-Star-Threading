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
	sf::Sprite m_mapSprite;
	sf::Texture m_mapTexture;
	NodeData m_nodeData;
	int from, to, weight;
	int const ROW = 20;
	int const COL = 20;

public:
	int m_tileIndex = 0;
	Map(int t_mapSize);
	void initMap();
	void update();
	void setUpArcs();
	void addTileNode(NodeData t_node);
	void draw(sf::RenderWindow& t_window);
	GraphNode<NodeData, int>* getNode(sf::Vector2i t_index);
	Graph<NodeData, int> & getGraph();
}; 