#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace std;
using namespace sf;

//vars
int fps = 60;
int width = 640;
int height = 480;
float dtr = 0.017453f;
RenderWindow window(VideoMode(width, height), "Asteroids");

int heading = 0;
class Ship{
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

};

int main() {
	window.setFramerateLimit(fps);
	Ship ship;
	bool thrust;
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

		ship.update();
		if (ship.pos.x < 0) ship.pos.x = width;
		if (ship.pos.x > width) ship.pos.x = 0;
		if (ship.pos.y < 0) ship.pos.y = height;
		if (ship.pos.y > height) ship.pos.y = 0;
		window.clear(Color(51,51,51));
		ship.render();
		window.display();
	}

	return 0;
}
