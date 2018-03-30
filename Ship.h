#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Ship
{
public:
	Vector2f vel = Vector2f(0, 0);
	Vector2f pos;
	int r;
	float dtr = 0.017453f;
	int heading = 0;
	Ship();
	void render();
	void update();
	void boost();
	void stop();
	void turn(int angle);
};

#endif // SHIP_H
