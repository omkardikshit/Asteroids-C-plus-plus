#include "Common.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int width = 640;
int height = 480;
int fps = 60;
Vector2f pos = Vector2f(width / 2, height / 2);
RenderWindow window(VideoMode(width, height), "Asteroids");
Common::Common()
{
    //ctor
}
