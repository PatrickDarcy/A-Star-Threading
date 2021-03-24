#include "Game.h"

const int static SCREEN_WIDTH = 800;
const int static SCREEN_HEIGHT = 600;

Game::Game() :
	window{ sf::VideoMode{SCREEN_WIDTH,SCREEN_HEIGHT,32}, "A Star Threading" }
{
	map1 = new Map(900,30,30);
	map2 = new Map(10000,100,100);
	map3 = new Map(1000000,1000,1000);

	for (int row = 0; row < map1->getRowCol().x; row++)
	{
		for (int col = 0; col < map1->getRowCol().y; col++)
		{
			NodeData tempNode;
			tempNode.m_cube.setSize(sf::Vector2f{10.0f, 10.0f});
			tempNode.m_cube.setFillColor(sf::Color::Green);
			tempNode.m_pathCost = 1;
			tempNode.m_positionX = row * 10;
			tempNode.m_positionY = col * 10;
			tempNode.m_cube.setPosition(tempNode.m_positionX, tempNode.m_positionY);
			map1->addTileNode(tempNode);
		}
	}
	map1->initMap();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (window.isOpen())
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
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
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
			window.close();
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time t_dt)
{
	map1->update();
}

void Game::render()
{
	window.clear();
	map1->draw(window);
	window.display();
}

