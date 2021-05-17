#pragma once

#include <vector>
#include <math.h>
#include <queue>
#include "Grid.h"
#include <iostream>
#include <mutex>

class AStar
{
public:
    static std::mutex s_lock;
    static std::vector<Node*>* GetPathAStar(Node* t_startPos, Node* t_endPos, Grid* t_grid, std::vector<Node*>* t_path);
    static float HeuristicCalc(sf::Vector2f t_startNode, sf::Vector2f t_endNode);
    static std::vector<Node*>* CalPath(Node* t_goalNode, std::vector<Node*>* t_path);
};

struct pq
{
    float operator()(Node* node1, Node* node2)
    {
        return node1->m_pathCost + node1->m_heuristic > node2->m_pathCost + node2->m_heuristic;
    };
};

