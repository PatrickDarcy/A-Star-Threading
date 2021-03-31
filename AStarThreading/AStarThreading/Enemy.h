#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class Enemy
{
private:

public:
	Enemy();
	void update(double dt);
	void render(sf::RenderWindow& t_window);

};


