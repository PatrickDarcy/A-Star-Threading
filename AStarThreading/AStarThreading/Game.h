#pragma once
#include <iostream>
#include "ThreadPool.h"
#include "SFML/Graphics.hpp"

class Game
{
private:

	sf::RenderWindow window;
	ThreadPool m_thread;

public:

	Game();
	void run();
	void processEvents();
	void update(sf::Time t_dt);
	void processGameEvents(sf::Event& t_event);
	void render();
};
