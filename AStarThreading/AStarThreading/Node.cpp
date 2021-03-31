#include "Node.h"

Node::Node(sf::Vector2f t_pos, NodeType t_nodeType) :
	m_pos{t_pos},
	m_nodeType{t_nodeType}
{
}

Node::~Node()
{
}
