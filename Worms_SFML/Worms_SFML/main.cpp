#include "includes.hpp"

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Worms_SFML", sf::Style::Fullscreen);

b2Vec2 gravity(0.0f, -10.0f);

int WINDOW_WIDTH = 1920;
int WINDOW_HEIGHT = 1080;
bool quit = false;

int main()
{
	box2dWorldInit();

	while (!quit)
	{
		Handler();

		window.clear();
		renderMenu(eventMenuRender);
		window.display();

	}
	return 0;
}

void box2dWorldInit() {
	b2AABB worldAABB;

	//Границы обсчёта физики
	worldAABB.lowerBound.Set(-100.0f, -100.0f);
	worldAABB.upperBound.Set(100.0f, 100.0f);
	//Создание мира
	b2World world(gravity);
}

void Handler() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed) {
			//
			}
		}
	}

