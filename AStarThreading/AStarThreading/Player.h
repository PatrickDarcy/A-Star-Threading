#pragma once
#include "SFML/Graphics.hpp"

class Player
{
private:
	sf::RectangleShape m_player;

public:
	Player();
	~Player();
	sf::Vector2f GetPlayerPos();
};

