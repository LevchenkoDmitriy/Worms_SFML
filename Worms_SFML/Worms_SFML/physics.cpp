#include <includes.hpp>

bool groundSavePhysics[2500][1000] = { false };
const float SCALE = 30.0f;
const double RAD = 57.2958;
b2Body* body[6];

void groundPhysics() {
	
	for (int i = 0; i < 2500; i++) {
		for (int j = 0; j < 1000; j++) {
			{
				if ((terrarian[i][j] == 1) && (groundSavePhysics[i][j] != 1) &&
					((terrarian[i][j + 1] == 0) ||
					(terrarian[i][j - 1] == 0) ||
						(terrarian[i + 1][j] == 0) ||
						((terrarian[i + 1][j - 1] == 0)) ||
						(terrarian[i + 1][j + 1] == 0) ||
						(terrarian[i - 1][j] == 0) ||
						(terrarian[i - 1][j + 1] == 0) ||
						(terrarian[i - 1][j - 1] == 0)))
				{
					groundSavePhysics[i][j] = true;
					b2BodyDef groundBodyDef;
					groundBodyDef.position.Set(i*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width)/SCALE,
						j*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height)/SCALE);
					

					b2Body* groundBody = world.CreateBody(&groundBodyDef);

					//b2CircleShape circle;
					b2CircleShape circle;
					circle.m_radius = 0.001 / SCALE;
					b2FixtureDef circleDef;
					circleDef.shape = &circle;
					circleDef.density = 0;
					circleDef.friction = 100.0f;


					groundBody->CreateFixture(&circleDef);
					
				}
			}
		}
	}
}

void wormGeneratePhysics() {
	for (int i = 0; i < 6; i++) {
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(worm[i].position.x*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width) / SCALE, 
			worm[i].position.y*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height) / SCALE);
		body[i] = world.CreateBody(&bodyDef);		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(0.4, 0.45);		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 10.0f;		body[i]->CreateFixture(&fixtureDef);
	}
}