#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{SCREEN_WIDTH,SCREEN_HEIGHT,32}, "A Star Threading" }
{
	m_grid.SetRectangle(GridType::Thirty);
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
		{
			m_numEnemies = 5;
			m_currentGrid = GridType::Thirty;
			m_grid.SetRectangle(GridType::Thirty);
			m_grid.SetGrid(GridType::Thirty);
			for (auto node : m_grid.GetNodes())
			{
				m_grid.SetNeighbourNodes(node);
			}
			m_enemies.clear();
			int randomPlayerNode1 = rand() % (10 - 0 + 1) + 10;
			m_player = Player(m_grid.GetNodes()[randomPlayerNode1]);
			for (int i = 0; i < m_numEnemies; i++)
			{
				int randomNode = rand() % (899 - 500 + 1) + 500;
				m_enemies.push_back(new Enemy(m_grid.GetNodeSize().x, m_grid.GetNodes()[randomNode], &m_player));
			}
			SetUpAStar();
			break;
		}
		case sf::Keyboard::Num2:
		{
			m_numEnemies = 50;
			m_currentGrid = GridType::Hundred;
			m_grid.SetRectangle(GridType::Hundred);
			m_grid.SetGrid(GridType::Hundred);
			for (auto node : m_grid.GetNodes())
			{
				m_grid.SetNeighbourNodes(node);
			}
			int randomPlayerNode2 = rand() % (10 - 0 + 1) + 10;
			m_player = Player(m_grid.GetNodes()[randomPlayerNode2]);
			m_enemies.clear();
			for (int i = 0; i < m_numEnemies; i++)
			{
				int randomNode = rand() % (9999 - 9500 + 1) + 9500;
				m_enemies.push_back(new Enemy(m_grid.GetNodeSize().x, m_grid.GetNodes()[randomNode], &m_player));
			}
			SetUpAStar();
			break;
		}
		case sf::Keyboard::Num3:
		{
			m_numEnemies = 500;
			m_currentGrid = GridType::Thousand;
			m_grid.SetRectangle(GridType::Thousand);
			m_grid.SetGrid(GridType::Thousand);
			for (auto node : m_grid.GetNodes())
			{
				m_grid.SetNeighbourNodes(node);
			}
			int randomPlayerNode3 = rand() % (10 - 0 + 1) + 10;
			m_player = Player(m_grid.GetNodes()[randomPlayerNode3]);
			m_enemies.clear();
			for (int i = 0; i < m_numEnemies; i++)
			{
				int randomNode = rand() % (999999 - 995000 + 1) + 995000;
				m_enemies.push_back(new Enemy(m_grid.GetNodeSize().x, m_grid.GetNodes()[randomNode], &m_player));
			}
			SetUpAStar();
			break;
		}
		default:
			break;
		}
	}
}

void Game::update(sf::Time t_dt)
{
	m_grid.Update();
	for (auto enemy : m_enemies)
	{
		enemy->Update(t_dt);
	}
	int x = 0;
}

void Game::render()
{
	m_window.clear();
	m_grid.Draw(m_window);
	for (auto m_enemy : m_enemies)
	{
		m_enemy->Render(m_window);
	}
	m_window.display();

}

void Game::SetUpAStar()
{
	for (int i = 0; i < m_numEnemies; i++)
	{
		m_enemies[i]->SetPath(*AStar::GetPathAStar( m_player.GetPlayerNode(), m_enemies[i]->GetEnemyNode(), &m_grid, &m_enemies[i]->m_path));
		//m_thread.addTask(bind(&AStar::GetPathAStar, m_player.GetPlayerNode(), m_enemies[i]->GetEnemyNode(), &m_grid, &m_enemies[i]->m_path));
	}
}

