#include "Asteroids.h"
#include <iostream>
#include <stdlib.h>
#include "Common.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

extern int width, height;
extern RenderWindow window;

Asteroids::Asteroids()
{
	radius = 25 + rand() % 25;
	vertex = 8+rand() % 12;
	pos = Vector2f(rand() % width,rand() % height);
	vel = Vector2f(1+rand() % 2, 1+rand() % 2);
	cout << "Pos: " << pos.x << "-" << pos.y << endl;
	cout << "Vel: " << vel.x << "-" << vel.y << endl;
	cout << "Rad: " << radius << " - " << "Ver: " << vertex << endl << endl;
	if(radius<=35){
        vel = Vector2f(1.9+rand() % 3, 1.9+rand() % 3);
        p = true;
	}
	if(radius >= 36){
        vel = Vector2f(0.8+rand() % 2, 0.8+rand() % 2);
        n = true;
    }
}

void Asteroids::update() {
	if(p){
        pos.x -= vel.x;
        pos.y -= vel.y;
    }else if(n){
        pos.x += vel.x;
        pos.y += vel.y;
    }

	if (pos.x < -radius*2)pos.x = width+radius*2;
	if (pos.y < -radius*2)pos.y = height+radius*2;
	if (pos.x > width+radius*2)pos.x = -radius*2;
	if (pos.y > height+radius*2)pos.y = -radius*2;
}

void Asteroids::render()
{
	CircleShape c(radius,vertex);
	c.setFillColor(Color(51, 51, 51));
	c.setOutlineColor(Color(255, 255, 255));
	c.setOutlineThickness(2);
	c.setPosition(pos);
	window.draw(c);
}
