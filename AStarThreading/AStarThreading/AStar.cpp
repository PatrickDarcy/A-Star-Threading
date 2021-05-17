#include "AStar.h"

//std::mutex AStar::s_lock;

std::vector<Node*>* AStar::GetPathAStar(Node* t_startPos, Node* t_endPos, Grid* t_grid, std::vector<Node*>* t_path)
{
    //s_lock.lock();
    Node* startNode = t_startPos;
    Node* endNode = t_endPos;

    std::priority_queue<Node*, std::vector<Node*>, pq>* m_openList = new std::priority_queue<Node*, std::vector<Node*>, pq>();
    std::vector<Node*>* m_closedList = new std::vector<Node*>;

    for (auto t_nodes : t_grid->GetNodes())
    {
        t_nodes->m_pathCost = INT_MAX;
        t_nodes->m_heuristic = INT_MAX;
        t_nodes->m_marked = false;
    }

    startNode->m_pathCost = 0;
    startNode->m_heuristic = HeuristicCalc(startNode->m_pos, endNode->m_pos);
    m_openList->push(startNode);

    while (m_openList->size() > 0)
    {
        Node* currentNode = m_openList->top();

        if (currentNode == endNode)
        {
            return CalPath(endNode, t_path);
            //s_lock.unlock();
        }

        m_openList->pop();
        m_closedList->push_back(currentNode);

        for (Node* node : *currentNode->m_neighbours)
        {

            int tentativeGCost = currentNode->m_pathCost + 1;

            if (tentativeGCost < node->m_pathCost && !node->m_marked)
            {
                node->m_previous = currentNode;
                node->m_pathCost = tentativeGCost;
                node->m_heuristic = HeuristicCalc(node->m_pos, endNode->m_pos);
                if (node->m_nodeType == NodeType::WALL)
                {
                    node->m_pathCost = INT_MAX;
                }

                if (node->m_marked == false)
                {
                    m_openList->push(node);
                }
                node->m_marked = true;
            }
        }
    }
    return nullptr;
    //s_lock.unlock();
}

float AStar::HeuristicCalc(sf::Vector2f t_startNode, sf::Vector2f t_endNode)
{
    return sqrt(pow(t_startNode.x - t_endNode.x, 2) + pow(t_startNode.y - t_endNode.y, 2));
}

std::vector<Node*>* AStar::CalPath(Node* t_goalNode, std::vector<Node*>* t_path)
{
    Node* current = t_goalNode->m_previous;
    std::vector<Node*>* m_path = new std::vector<Node*>;
    while (current != nullptr)
    {
        m_path->push_back(current);
        current = current->m_previous;
    }
    return m_path;
    t_path = m_path;
}
