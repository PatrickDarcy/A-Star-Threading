#pragma once
#include <iostream>
#include "ThreadPool.h"
#include "SFML/Graphics.hpp"
#include "Map.h"
#include "NodeData.h"

class Game
{
private:

	sf::RenderWindow window;
	ThreadPool m_thread;
	Map* map1;
	Map* map2;
	Map* map3;

public:

	Game();
	void run();
	void processEvents();
	void update(sf::Time t_dt);
	void processGameEvents(sf::Event& t_event);
	void render();
};
