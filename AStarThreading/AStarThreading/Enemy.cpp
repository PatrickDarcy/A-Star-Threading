#include "Enemy.h"

Enemy::Enemy(float t_enemySize, sf::Vector2i t_enemyPos)
{
	m_enemyShape.setFillColor(sf::Color::Red);
	m_enemyShape.setSize(sf::Vector2f(t_enemySize, t_enemySize));
	m_enemyShape.setPosition((sf::Vector2f)t_enemyPos);
}

void Enemy::update(double dt)
{
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemyShape);
}

void Enemy::setPos(sf::Vector2f t_pos)
{
	m_enemyShape.setPosition(t_pos);
}

sf::Vector2f Enemy::getPos()
{
	return m_enemyShape.getPosition();
}
