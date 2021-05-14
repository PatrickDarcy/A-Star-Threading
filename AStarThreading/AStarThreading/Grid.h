#pragma once
#include "Node.h"
#include "SFML/Graphics.hpp"
#include "Gloabls.h"

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
	void SetRectangle(GridType t_gridType);
	void SetGrid(GridType t_gridType);
	void Update();
	void Draw(sf::RenderWindow& t_window);
	void SetNeighbourNodes(Node* t_current);
	float GetGridDimensions();
	sf::Vector2f GetNodeSize();
	std::vector<Node*> GetNodes();
};
