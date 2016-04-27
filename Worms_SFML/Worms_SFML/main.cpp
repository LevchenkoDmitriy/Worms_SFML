#include "includes.hpp"

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Worms_SFML", sf::Style::Fullscreen);
sf::Clock elapsedTime;

b2Vec2 gravity(0.0f, -10.0f);

int WINDOW_WIDTH = 1366;
int WINDOW_HEIGHT = 768;
bool quit = false;
b2AABB worldAABB;
bool doSleep = true;


int main()
{
	//Границы обсчёта физики
	worldAABB.lowerBound.Set(-100.0f, -100.0f);
	worldAABB.upperBound.Set(100.0f, 100.0f);
	//Создание мира
	b2World world(gravity);
	world.SetAllowSleeping(doSleep);

	while (!quit)
	{
		Handler();

		window.clear();
		renderMenu(eventMenuRender);
		gameSettings(eventGameSettingsRender);
		gameStart(eventGameStart);
		window.display();

	}
	return 0;
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

