#pragma once
#include "SFML/Graphics.hpp"
#include "Node.h"
#include "Grid.h"

class Player
{
private:
	sf::RectangleShape m_player;

public:
	Player();
	~Player();
	sf::Vector2f GetPlayerPos();
};

