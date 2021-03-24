#include "Map.h"

Map::Map(int t_mapSize, int t_row, int t_col) :
	nodeMap(t_mapSize),
	m_row(t_row),
	m_col(t_col),
	m_numOfNodes(t_mapSize)
{
}
void Map::initMap()
{
	for (int i = 0; i < m_numOfNodes; i++)
	{
		if (nodeMap.nodeIndex(i) != NULL)
		{
			nodeMap.setNodeNeighbours(nodeMap.nodeIndex(i));
		}
	}
	setUpArcs();
}

void Map::addTileNode(NodeData t_node)
{
	nodeMap.addNode(t_node, m_tileIndex);
	m_tileIndex++;
}
void Map::update()
{
}

void Map::setUpArcs()
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			for (int direction = 0; direction < 9; direction++)
			{
				if (direction == 4) continue; // Skip 4, this is ourself.
				if (direction == 0) continue;
				if (direction == 2) continue;
				if (direction == 6) continue;
				if (direction == 8) continue;

				int n_row = row + ((direction / 3) - 1);
				int n_col = col + ((direction % 3) - 1);

				if (n_row >= 0 && n_row < 20 && n_col >= 0 && n_col < 20)
				{
						int startIndex = (row * 20) + col;
						int endIndex = (n_row * 20) + n_col;
						nodeMap.addArc(startIndex, endIndex , 50);
				}
			}
		}
	}
}

void Map::draw(sf::RenderWindow& t_window)
{
	//for(auto node : nodeMap)
}

GraphNode<NodeData, int>* Map::getNode(sf::Vector2i t_index)
{
	int index = (t_index.y * 20) + t_index.x;
	return nodeMap.nodeIndex(index);
}

Graph<NodeData, int> & Map::getGraph()
{
	return nodeMap;
}
