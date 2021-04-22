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
	float m_gridDimensions;
	float m_distNode = 5.5f;
public:
	Grid();
	~Grid();
	void setRectangle(GridType t_gridType);
	void setGrid(GridType t_gridType);
	void update();
	void draw(sf::RenderWindow& t_window);
	sf::Vector2f getNodeSize();
};

