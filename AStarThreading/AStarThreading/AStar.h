#include <vector>
#include "Node.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"
#include <cmath>

class AStar
{
private:
    std::vector<Node>* m_openList;
    std::vector<Node>* m_closedList;
    Grid* m_grid;
    std::vector<Node*> m_gridNodes;

public:
    AStar(Grid* t_grid);
    ~AStar();
    std::vector<Node> GetPathAStar(Node t_startPos, Node t_endPos);
    float Introp(sf::Vector2f t_startNode, sf::Vector2f t_endNode);
};

AStar::AStar(Grid* t_grid)
{
    m_grid = t_grid;
    m_gridNodes = m_grid->GetNodes();
}

AStar::~AStar()
{

}

std::vector<Node> AStar::GetPathAStar(Node t_startPos, Node t_endPos)
{
    Node startNode = t_startPos;
    Node endNode = t_endPos;

    m_openList = new std::vector<Node>; // change to priority queue
    m_closedList = new std::vector<Node>;

    for (auto t_nodes : m_gridNodes)
    {
        t_nodes->m_pathCost = INT_MAX;
        t_nodes->m_heuristic = INT_MAX;
        t_nodes->m_neighbour = new std::vector<Node*>;
    }

    startNode.m_pathCost = 0;
    startNode.m_heuristic = Introp(startNode.m_pos, endNode.m_pos);

    while (m_openList->size() > 0)
    {
    }
}

float AStar::Introp(sf::Vector2f t_startNode, sf::Vector2f t_endNode)
{
    return sqrt(pow(t_startNode.x - t_endNode.x, 2) + pow(t_startNode.y - t_endNode.y, 2));
}


 std::vector<TileMap.TileMapObject> getPathAStar(int startX, int startY, int endX, int endY)
{
    TileMap.TileMapObject startNode = getObject(startX, startY);
    TileMap.TileMapObject endNode = getObject(endX, endY);


    openList = new List<TileMap.TileMapObject>{ startNode };
    closedList = new List<TileMap.TileMapObject>();

    for (int x = 0; x < tileMap.GetGridMap().getWidth(); x++)
    {
        for (int y = 0; y < tileMap.GetGridMap().getHeight(); y++)
        {
            TileMap.TileMapObject pathNode = tileMap.GetGridMap().getGridObject(x, y);

            pathNode.m_pathCost = int.MaxValue;
            pathNode.calFcost();
            pathNode.m_previous = null;
        }
    }

    startNode.m_pathCost = 0;
    startNode.m_hueristic = m_interop.AStarHeuristicCalculation(startNode.x, startNode.y, endNode.x, endNode.y, MOVE_DIAGONAL, MOVE_STRAIGHT); //calculateHeuristic(startNode, endNode);
    startNode.calFcost();

    while (openList.Count > 0)
    {
        TileMap.TileMapObject currentNode = lowestPathNode(openList);

        if (currentNode == endNode)
        {
            return calPath(endNode);
        }

        openList.Remove(currentNode);
        closedList.Add(currentNode);

        foreach(TileMap.TileMapObject neighbourNode in getNeighBours(currentNode))
        {

            if (closedList.Contains(neighbourNode))
            {
                continue;
            }

            int tentativeGCost = currentNode.m_pathCost + m_interop.AStarHeuristicCalculation(currentNode.x, currentNode.y, neighbourNode.x, neighbourNode.y, MOVE_DIAGONAL, MOVE_STRAIGHT); ;

            if (tentativeGCost < neighbourNode.m_pathCost)
            {
                neighbourNode.m_previous = currentNode;
                neighbourNode.m_pathCost = tentativeGCost;
                neighbourNode.m_hueristic = calculateHeuristic(neighbourNode, endNode);
                neighbourNode.calFcost();

                if (openList.Contains(neighbourNode) == false)
                {
                    openList.Add(neighbourNode);
                }
            }
        }

    }

    return null;

}