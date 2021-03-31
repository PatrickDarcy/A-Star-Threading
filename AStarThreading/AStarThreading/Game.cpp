#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{SCREEN_WIDTH,SCREEN_HEIGHT,32}, "A Star Threading" }
{
	m_grid.setGrid(GridType::Thirty);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}

		processGameEvents(event);
	}
}
void Game::processGameEvents(sf::Event& t_event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == t_event.type)
	{
		switch (t_event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;
		case sf::Keyboard::Num1:
			m_grid.setGrid(GridType::Thirty);
			break;
		case sf::Keyboard::Num2:
			m_grid.setGrid(GridType::Hundred);
			break;
		case sf::Keyboard::Num3:
			m_grid.setGrid(GridType::Thousand);
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time t_dt)
{
	m_grid.update();
}

void Game::render()
{
	m_window.clear();
	m_grid.draw(m_window);
	m_window.display();
}

