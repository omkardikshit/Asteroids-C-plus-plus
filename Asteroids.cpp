#include "Asteroids.h"
#include <iostream>
#include <stdlib.h>
#include "Common.h"
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

extern int width, height;
extern RenderWindow window;

Asteroids::Asteroids()
{
	r = 25 + rand() % 25;
	s = 8+rand() % 12;
	pos = Vector2f(rand() % width,rand() % height);
	vel = Vector2f(1+rand() % 2, 1+rand() % 2);
	cout << pos.x << "-" << pos.y << endl;
	cout << vel.x << "-" << vel.y << endl;
}

void Asteroids::update() {
	pos.x += vel.x;
	pos.y += vel.y;
	if (pos.x < 0)pos.x = width;
	if (pos.y < 0)pos.y = height;
	if (pos.x > width)pos.x = 0;
	if (pos.y > height)pos.y = 0;
}

void Asteroids::render() 
{
	CircleShape c(r,s);
	c.setFillColor(Color(51, 51, 51));
	c.setOutlineColor(Color(255, 255, 255));
	c.setOutlineThickness(2);
	c.setPosition(pos);
	window.draw(c);
}
