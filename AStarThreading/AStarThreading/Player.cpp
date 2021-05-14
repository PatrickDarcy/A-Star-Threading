#include "Player.h"

Player::Player(Node* t_playerNode)
{
	m_playerNode = t_playerNode;
	m_player.setPosition(m_playerNode->m_pos);
}

Player::~Player()
{
}

sf::Vector2f Player::GetPlayerPos()
{
	return m_player.getPosition();
}

Node* Player::GetPlayerNode()
{
	return m_playerNode;
}
