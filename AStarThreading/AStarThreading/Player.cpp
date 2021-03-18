#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

sf::Vector2f Player::GetPlayerPos()
{
	return m_player.getPosition();
}

GraphNode<NodeData, int>* Player::GetCurrentNode()
{
	return m_currentNode;
}
