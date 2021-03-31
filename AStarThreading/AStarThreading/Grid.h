#pragma once
#include "Node.h"
#include "SFML/Graphics.hpp"

class Grid;

enum GridType {
	Thirty,
	Hundred,
	Thousand
};

class Grid
{
private:
	sf::RectangleShape m_node;
	std::vector<Node*> m_grid;
	int m_gridDimensions;
	float m_distNode = 5.5f;
public:
	Grid();
	~Grid();
	void setGrid(GridType t_gridType, sf::RenderWindow& t_window);
	void update();
	void draw(sf::RenderWindow& t_window);
};

