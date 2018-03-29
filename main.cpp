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
extern RenderWindow window;

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

		if (ship.pos.x < 0) ship.pos.x = width;
		if (ship.pos.x > width) ship.pos.x = 0;
		if (ship.pos.y < 0) ship.pos.y = height;
		if (ship.pos.y > height) ship.pos.y = 0;

		ship.update();
		window.clear(Color(51,51,51));
		ship.render();
		window.display();
	}

	return 0;
}
