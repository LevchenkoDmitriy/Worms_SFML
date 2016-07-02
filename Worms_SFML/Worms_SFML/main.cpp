#include "includes.hpp"

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Worms_SFML", sf::Style::Fullscreen);
sf::Clock elapsedTime;

b2Vec2 gravity(0.0f, 10.0f);

int WINDOW_WIDTH = 1366;
int WINDOW_HEIGHT = 768;
bool quit = false;
b2World world(gravity);

int main()
{
	window.setFramerateLimit(60);

	sf::Texture boxTexture;
	boxTexture.loadFromFile("box.png");
	boxTexture.setSmooth(true);

	sf::Sprite boxSprite(boxTexture);
	boxSprite.setOrigin(45.0f, 45.0f);
	
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(1000/SCALE, 50/SCALE);
	b2Body* body = world.CreateBody(&bodyDef);	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.5f, 1.5f);	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 5.0f;
	fixtureDef.friction = 0.03f;	body->CreateFixture(&fixtureDef);	float32 timeStep = 1.0f / 60.0f;	int32 velocityIterations = 8;
	int32 positionIterations = 3;

	while (!quit)
	{
		Handler();

		window.clear();
		
		world.Step(timeStep, velocityIterations, positionIterations);
		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

		boxSprite.setPosition(position.x*SCALE, position.y*SCALE);
		boxSprite.setRotation(angle*RAD);

		renderMenu(eventMenuRender);
		gameSettings(eventGameSettingsRender);
		gameStart(eventGameStart);

		window.draw(boxSprite);
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				WormMoving.wormJump();
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) &&
				(sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
				WormMoving.wormJumpLeft();
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) &&
				(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
				WormMoving.wormJumpRight();
			}
			}
			}
		}

