#include "Grid.h"
#include "Game.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::SetRectangle(GridType t_gridType)
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

void Grid::SetGrid(GridType t_gridType)
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

				if (i == 6 && j <= 18 || 
					i == 15 && j <= 22 && j >= 4 ||
					i == 19 && j <= 20 && j >= 3)
					t_node->m_nodeType = NodeType::WALL;

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

				if (i == 10 && j <= 89 && j >= 18 ||
					i == 25 && j <= 76 ||
					i == 40 && j <= 80 && j >= 12 ||
					i == 55 && j <= 75 && j >= 17 ||
					i == 66 && j <= 78 ||
					i == 74 && j <= 90 && j >= 20)
					t_node->m_nodeType = NodeType::WALL;

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

				if (i == 100 && j <= 890 && j >= 180 ||
					i == 166 && j <= 879 && j >= 123 ||
					i == 200 && j <= 820 && j >= 150 ||
					i == 222 && j <= 875 && j >= 143 ||
					i == 250 && j >= 160 ||
					i == 280 && j <= 890 ||
					i == 301 && j <= 894 && j >= 212 ||
					i == 340 && j <= 750 && j >= 200 ||
					i == 378 && j <= 865 && j >= 111 ||
					i == 400 && j <= 800 && j >= 120 ||
					i == 430 && j <= 888 && j >= 222 ||
					i == 478 && j <= 912 && j >= 298 ||
					i == 511 && j <= 798 && j >= 101 ||
					i == 550 && j <= 750 && j >= 170 ||
					i == 587 && j <= 420 && j >= 69 ||
					i == 660 && j <= 780 ||
					i == 710 && j >= 150 ||
					i == 740 && j <= 900 && j >= 200)

					t_node->m_nodeType = NodeType::WALL;

				m_grid.push_back(t_node);
			}
		}
		break;
	default:
		break;
	}
}

void Grid::Update()
{
}

void Grid::Draw(sf::RenderWindow& t_window)
{
	for (auto t_node : m_grid)
	{
		m_node.setPosition(t_node->m_pos);
		if (t_node->m_nodeType == NodeType::WALL)
			m_node.setFillColor(sf::Color::Black);
		else
			m_node.setFillColor(sf::Color::Green);
		t_window.draw(m_node);
	}
}

float Grid::GetGridDimensions()
{
	return m_gridDimensions;
}

sf::Vector2f Grid::GetNodeSize()
{
	return m_node.getSize();
}

std::vector<Node*> Grid::GetNodes()
{
	return m_grid;
}

