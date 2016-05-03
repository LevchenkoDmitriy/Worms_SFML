#include "includes.hpp"

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Worms_SFML", sf::Style::Fullscreen);
sf::Clock elapsedTime;
float CurrentFrame = 0;//������ ������� ����
b2Vec2 gravity(0.0f, 20.0f);

int WINDOW_WIDTH = 1920;
int WINDOW_HEIGHT = 1080;

bool quit = false;
b2World world(gravity);

int main()
{
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(true);

	while (!quit)
	{	
		Handler();
		
		window.clear();

		renderMenu(eventMenuRender);
		gameSettings(eventGameSettingsRender);
		gameStart(eventGameStart);
		window.setView(camera);//"��������" ������ � ���� sfml

		window.display();

	}
	
	return 0;
}

void Handler() {
	wormMoving WormMoving;
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				WormMoving.wormMoveLeft();
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				WormMoving.wormMoveRight();
				
			}
		/*	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				WormMoving.wormJump();
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) &&
				(sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
				WormMoving.wormJumpLeft();
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) &&
				(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
				WormMoving.wormJumpRight();
			}*/
			}
			}
		}

