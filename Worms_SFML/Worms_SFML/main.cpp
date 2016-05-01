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
	sf::Texture boxTexture;
	boxTexture.loadFromFile("box.png");
	sf::Sprite boxSprite(boxTexture);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(90 /SCALE, 90/SCALE);

	b2BodyDef bdef;
	bdef.type = b2_dynamicBody;
	//bdef.position.Set(0, 0);


	b2Body *body = world.CreateBody(&bdef);
	body->SetActive(true);
	body->CreateFixture(&boxShape, 2);
	body->SetUserData("box");
	
	while (!quit)
	{
		Handler();

		window.clear();

		b2Vec2 pos = body->GetPosition();
		float angle = body->GetAngle();

		printf("%f %f\n", pos.x, pos.y);
		boxSprite.setPosition(pos.x*SCALE, pos.y*SCALE);
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
		if (event.type == sf::Event::KeyPressed) {
			//
			}
		}
	}

