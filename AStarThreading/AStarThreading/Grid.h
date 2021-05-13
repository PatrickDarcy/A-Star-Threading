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
	void SetRectangle(GridType t_gridType);
	void SetGrid(GridType t_gridType);
	void Update();
	void Draw(sf::RenderWindow& t_window);
	float GetGridDimensions();
	sf::Vector2f GetNodeSize();
	std::vector<Node*> GetNodes();
};

