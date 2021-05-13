#include "Enemy.h"

Enemy::Enemy(float t_enemySize, sf::Vector2i t_enemyPos, Grid* t_grid, Player* t_player)
{
	m_enemyShape.setFillColor(sf::Color::Red);
	m_enemyShape.setSize(sf::Vector2f(t_enemySize, t_enemySize));
	m_enemyShape.setPosition((sf::Vector2f)t_enemyPos);
	m_grid = t_grid;
	m_player = t_player;
}

void Enemy::Update(double dt)
{
	m_moveTime += dt;
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
	if (m_delay < m_path.size() && m_moveTime > 100)
	{
		m_enemyShape.setPosition(m_path.at(m_delay)->m_pos);
		m_delay++;
		m_moveTime = 0;
	}

	else
	{
		m_delay = 0;
	}
}
