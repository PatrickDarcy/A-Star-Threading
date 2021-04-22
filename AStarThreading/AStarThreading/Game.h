#pragma once
#include <iostream>
#include "ThreadPool.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"
#include "Enemy.h"

const int static SCREEN_WIDTH = 1000;
const int static SCREEN_HEIGHT = 1000;

class Game
{
private:

	sf::RenderWindow m_window;
	ThreadPool m_thread;
	Grid m_grid;
	GridType m_currentGrid;
	std::vector<Enemy*> m_enemies;

public:

	Game();
	void run();
	void processEvents();
	void update(sf::Time t_dt);
	void processGameEvents(sf::Event& t_event);
	void render();
	sf::Vector2i getEnemySpawn();
};
