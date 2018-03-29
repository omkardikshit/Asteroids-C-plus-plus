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
