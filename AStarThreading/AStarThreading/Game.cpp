#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{SCREEN_WIDTH,SCREEN_HEIGHT,32}, "A Star Threading" }
{
	m_grid.setRectangle(GridType::Thirty);
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
			m_currentGrid = GridType::Thirty;
			m_grid.setRectangle(GridType::Thirty);
			m_grid.setGrid(GridType::Thirty);
			m_enemies.clear();
			for (int i = 0; i < 5; i++)
			{
				m_enemies.push_back(new Enemy(m_grid.getNodeSize().x, getEnemySpawn()));
			}
			getEnemySpawn();
			break;
		case sf::Keyboard::Num2:
			m_currentGrid = GridType::Hundred;
			m_grid.setRectangle(GridType::Hundred);
			m_grid.setGrid(GridType::Hundred);
			m_enemies.clear();
			for (int i = 0; i < 50; i++)
			{
				m_enemies.push_back(new Enemy(m_grid.getNodeSize().x, getEnemySpawn()));
			}
			getEnemySpawn();
			break;
		case sf::Keyboard::Num3:
			m_currentGrid = GridType::Thousand;
			m_grid.setRectangle(GridType::Thousand);
			m_grid.setGrid(GridType::Thousand);
			m_enemies.clear();
			for (int i = 0; i < 500; i++)
			{
				m_enemies.push_back(new Enemy(m_grid.getNodeSize().x, getEnemySpawn()));
			}
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
	for (auto m_enemy : m_enemies)
	{
		m_enemy->render(m_window);
	}
	m_window.display();

}

sf::Vector2i Game::getEnemySpawn()
{
	sf::Vector2i t_position = sf::Vector2i(-1,-1);
	switch (m_currentGrid)
	{
	case GridType::Thirty:
		t_position = sf::Vector2i((m_grid.getNodeSize().x * (rand() % 10 + 20)),(m_grid.getNodeSize().y * (rand() % 20 + 5)));
		break;
	case GridType::Hundred:
		t_position = sf::Vector2i((m_grid.getNodeSize().x * (rand() % 30 + 65)), (m_grid.getNodeSize().y * (rand() % 60 + 20)));
		break;
	case GridType::Thousand:
		t_position = sf::Vector2i((m_grid.getNodeSize().x * (rand() % 300 + 650)), (m_grid.getNodeSize().y * (rand() % 600 + 200)));
		break;
	default:
		break;
	}
	return t_position;
}

