#include "Enemy.h"



Enemy::Enemy()
{
	m_enemyMoveDelay = 0;
	m_delay = 0;
}

void Enemy::initEnemy()
{
	m_playerCurrentNode = m_player->GetCurrentNode();
}

void Enemy::update(double dt)
{
	m_findPlayerTime += dt;
	m_moveTime += dt;

	if (m_findPlayerTime >= m_delayTime)
	{
		m_findPlayerTime = 0;

		m_playerCurrentNode = m_player->GetCurrentNode();

		m_map->getGraph().aStar(m_map->getNode(m_enemyIndex), m_playerCurrentNode, m_path);
	}

	if (m_path.size() != 0)
	{
		moveToPlayer();
	}
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemy);
}

void Enemy::setMapPointer(Map* t_map)
{
	m_map = t_map;
}

void Enemy::setPlayer(Player* t_player)
{
	m_player = t_player;
}

void Enemy::moveToPlayer()
{
	if (m_delay < m_path.size() && m_moveTime > 100)
	{
		m_enemy.setPosition(m_path.at(m_delay)->m_data.m_positionX, m_path.at(m_delay)->m_data.m_positionY);
		m_enemyIndex.x = m_path.at(m_delay)->m_data.m_index % m_rowColSize;
		m_enemyIndex.y = m_path.at(m_delay)->m_data.m_index / m_rowColSize;
		m_delay++;
		m_moveTime = 0;
	}

	else
	{
		m_delay = 0;
	}
}
