#include "Grid.h"
#include "Game.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::setRectangle(GridType t_gridType)
{
	switch (t_gridType)
	{
	case GridType::Thirty:
		m_gridDimensions = 30;
		m_node.setSize(sf::Vector2f(SCREEN_WIDTH/m_gridDimensions, SCREEN_HEIGHT /m_gridDimensions));
		m_node.setFillColor(sf::Color::Green);
		m_node.setOutlineColor(sf::Color::Black);
		m_node.setOutlineThickness(1.0f);
		break;
	case GridType::Hundred:
		m_gridDimensions = 100;
		m_node.setSize(sf::Vector2f(SCREEN_WIDTH / m_gridDimensions, SCREEN_HEIGHT / m_gridDimensions));
		m_node.setFillColor(sf::Color::Green);
		m_node.setOutlineColor(sf::Color::Black);
		m_node.setOutlineThickness(1.0f);
		break;
	case GridType::Thousand:
		m_gridDimensions = 1000;
		m_node.setSize(sf::Vector2f(SCREEN_WIDTH / m_gridDimensions, SCREEN_HEIGHT / m_gridDimensions));
		m_node.setFillColor(sf::Color::Green);
		m_node.setOutlineColor(sf::Color::Black);
		m_node.setOutlineThickness(0);
		break;
	default:
		break;
	}

}

void Grid::setGrid(GridType t_gridType)
{
	m_grid.clear();
	switch (t_gridType)
	{
	case GridType::Thirty:
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				Node *t_node = new Node();
				t_node->m_pos = sf::Vector2f(i * (SCREEN_WIDTH / m_gridDimensions), j * (SCREEN_WIDTH / m_gridDimensions));
				m_grid.push_back(t_node);
			}
		}
		break;
	case GridType::Hundred:
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				Node* t_node = new Node();
				t_node->m_pos = sf::Vector2f(i * (SCREEN_WIDTH / m_gridDimensions), j * (SCREEN_WIDTH / m_gridDimensions));
				m_grid.push_back(t_node);
			}
		}
		break;
	case GridType::Thousand:
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				Node* t_node = new Node();
				t_node->m_pos = sf::Vector2f(i * (SCREEN_WIDTH / m_gridDimensions), j * (SCREEN_WIDTH / m_gridDimensions));
				m_grid.push_back(t_node);
			}
		}
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

	for (auto t_node : m_grid)
	{
		m_node.setPosition(t_node->m_pos);
		t_window.draw(m_node);
	}
}

sf::Vector2f Grid::getNodeSize()
{
	return m_node.getSize();
}
