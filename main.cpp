#include <iostream>
#include <SFML/Graphics.hpp>
#include "Common.h"
#include "Ship.h"

using namespace std;
using namespace sf;
//vars
extern int width;
extern int height;
extern int fps;
extern Vector2f pos;
extern RenderWindow window;
/*class Ship{
public:
	Vector2f pos = Vector2f(width / 2, height / 2);
	int r = 20;
	int x  = 0;
	Vector2f vel = Vector2f(0, 0);
	void render() {
		ConvexShape convex;
		convex.setPointCount(3);
		convex.setPoint(0, Vector2f(-r, r));
		convex.setPoint(1, Vector2f(r, r));
		convex.setPoint(2, Vector2f(0, -r));
		convex.setPosition(pos);
		convex.setFillColor(Color(51, 51, 51));
		convex.setOutlineColor(Color(255, 255, 255));
		convex.setOutlineThickness(2);
		convex.setRotation(heading+90);
		window.draw(convex);
	}

	void update() {
		pos += vel;
		vel.x *= 0.97;
		vel.y *= 0.97;
	}

	void boost() {
		Vector2f force = Vector2f(cos(heading*dtr)*0.2,sin(heading*dtr)*0.2);
		vel.x += force.x;
		vel.y += force.y;
	}

	void stop(){
		Vector2f force = Vector2f(0,0);
		vel.x *= force.x;
		vel.y *= force.y;
	}

	void turn(int angle) {
		heading += angle;
	}

};*/

int main() {
	window.setFramerateLimit(fps);
	Ship ship;
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) ship.turn(-5);
		if (Keyboard::isKeyPressed(Keyboard::Right)) ship.turn(5);
		if (Keyboard::isKeyPressed(Keyboard::Up)) ship.boost();
		if (Keyboard::isKeyPressed(Keyboard::Down)) ship.stop();

		if (pos.x < 0) pos.x = width;
		if (pos.x > width) pos.x = 0;
		if (pos.y < 0) pos.y = height;
		if (pos.y > height) pos.y = 0;

		ship.update();
		window.clear(Color(51,51,51));
		ship.render();
		window.display();
	}

	return 0;
}
