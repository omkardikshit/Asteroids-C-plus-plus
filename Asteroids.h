#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Asteroids
{
public:
	Vector2f pos;
	Vector2f vel;
	Asteroids();
	void render();
	void update();
	int r,s;
};

