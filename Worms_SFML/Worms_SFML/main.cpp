#include "includes.hpp"
#include "main.hpp"
#include "render.hpp"

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Worms_SFML");

b2Vec2 gravity(0.0f, -10.0f);

int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;

int main()
{
	box2dWorldInit();

	while (window.isOpen())
	{
		Handler();
		window.clear();
		window.display();

	}
	return 0;
}

void box2dWorldInit() {
	b2AABB worldAABB;

	//Границы обсчёта физики
	worldAABB.lowerBound.Set(-100.0f, -100.0f);
	worldAABB.upperBound.Set(100.0f, 100.0f);

	b2World world(gravity);
}

void Handler() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
