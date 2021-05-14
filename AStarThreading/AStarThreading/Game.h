#pragma once
#include <iostream>
#include "ThreadPool.h"
#include "SFML/Graphics.hpp"
#include "Enemy.h"
#include "AStar.h"

class Game
{
private:

	sf::RenderWindow m_window;
	ThreadPool m_thread;
	Grid m_grid;
	GridType m_currentGrid;
	std::vector<Enemy*> m_enemies;
	Player m_player;
	float m_numEnemies;

public:

	Game();
	void run();
	void processEvents();
	void update(sf::Time t_dt);
	void processGameEvents(sf::Event& t_event);
	void render();
	sf::Vector2i getEnemySpawn();
	void SetUpAStar();
};
