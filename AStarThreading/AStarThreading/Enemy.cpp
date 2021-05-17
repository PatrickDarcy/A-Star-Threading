#include "Enemy.h"

Enemy::Enemy(float t_enemySize, Node* t_enemyNode, Player* t_player)
{
	m_enemyShape.setFillColor(sf::Color::Red);
	m_enemyShape.setSize(sf::Vector2f(t_enemySize, t_enemySize));
	m_enemyShape.setPosition(t_enemyNode->m_pos);
	m_enemyNode = t_enemyNode;
	m_player = t_player;
}

void Enemy::Update(sf::Time dt)
{
	m_moveTime += dt.asSeconds();
	if (m_enemyNode != m_player->GetPlayerNode())
	{
		MoveToPlayer();
	}
	else
		int v = 0;
}

void Enemy::Render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemyShape);
}

void Enemy::SetPos(sf::Vector2f t_pos)
{
	m_enemyShape.setPosition(t_pos);
}

sf::Vector2f Enemy::GetPos()
{
	return m_enemyShape.getPosition();
}

void Enemy::MoveToPlayer()
{
	if (m_delay < m_path.size())
	{
		m_enemyShape.setPosition(m_path.at(m_delay)->m_pos);
		m_delay++;
	}

	else
	{
		m_delay = 0;
	}
}

