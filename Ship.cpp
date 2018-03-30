#include "Ship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Common.h"
#include <math.h>
#include "Asteroids.h"

using namespace std;
using namespace sf;

extern RenderWindow window;
extern int width, height;
Ship::Ship()
{
	this->pos = Vector2f(width / 2, height / 2);
	this->r = 20;

}

void Ship::render() {
	ConvexShape convex;
	convex.setPointCount(3);
	convex.setPoint(0, Vector2f(-this->r, this->r));
	convex.setPoint(1, Vector2f(this->r, this->r));
	convex.setPoint(2, Vector2f(0, -this->r));
	convex.setPosition(pos);
	convex.setFillColor(Color(51, 51, 51));
	convex.setOutlineColor(Color(255, 255, 255));
	convex.setOutlineThickness(2);
	convex.setRotation(heading + 90);
	window.draw(convex);
}

void Ship::update() {
	pos += vel;
	vel.x *= 0.98;
	vel.y *= 0.98;
}

void Ship::boost() {
	Vector2f force = Vector2f(cos(heading*dtr)*0.2, sin(heading*dtr)*0.2);
	vel += force;
}

void Ship::stop() {
	Vector2f force = Vector2f(0.9, 0.9);
	vel.x *= force.x;
	vel.y *= force.y;
}

void Ship::turn(int angle) {
	heading += angle;
}
