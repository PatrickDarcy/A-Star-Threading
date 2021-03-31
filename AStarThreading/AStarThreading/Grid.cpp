#include "Grid.h"
#include "Game.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::setGrid(GridType t_gridType, sf::RenderWindow & t_window)
{
	switch (t_gridType)
	{
	case GridType::Thirty:
		m_gridDimensions = 30;
		m_node.setSize(sf::Vector2f(SCREEN_WIDTH/m_gridDimensions, SCREEN_HEIGHT /m_gridDimensions));
		m_node.setFillColor(sf::Color::White);
		m_node.setOutlineColor(sf::Color::Black);
		break;
	case GridType::Hundred:
		m_gridDimensions = 100;
		m_node.setSize(sf::Vector2f(SCREEN_WIDTH / m_gridDimensions, SCREEN_HEIGHT / m_gridDimensions));
		m_node.setFillColor(sf::Color::White);
		m_node.setOutlineColor(sf::Color::Black);
		break;
	case GridType::Thousand:
		m_gridDimensions = 1000;
		m_node.setSize(sf::Vector2f(SCREEN_WIDTH / m_gridDimensions, SCREEN_HEIGHT / m_gridDimensions));
		m_node.setFillColor(sf::Color::White);
		m_node.setOutlineColor(sf::Color::Black);
		break;
	default:
		break;
	}

}

void Grid::update()
{
}

void Grid::draw(sf::RenderWindow& t_window)
{

}
