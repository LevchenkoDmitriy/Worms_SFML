#include "includes.hpp"

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Worms_SFML", sf::Style::Fullscreen);
sf::Clock elapsedTime;

b2Vec2 gravity(0.0f, 10.0f);

int WINDOW_WIDTH = 1920;
int WINDOW_HEIGHT = 1080;
bool quit = false;
b2World world(gravity);

int main()
{
	sf::Texture boxTexture;
	boxTexture.loadFromFile("box.png");
	sf::Sprite boxSprite(boxTexture);

	/*b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);	b2Body* groundBody = world.CreateBody(&groundBodyDef);	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);	groundBody->CreateFixture(&groundBox, 0.0f);*/	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&bodyDef);	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;	body->CreateFixture(&fixtureDef);	float32 timeStep = 1.0f / 11.0f;	int32 velocityIterations = 6;
	int32 positionIterations = 2;

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
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		/*if (event.type == sf::Event::KeyPressed) {
			//
			}*/
		}
	}

