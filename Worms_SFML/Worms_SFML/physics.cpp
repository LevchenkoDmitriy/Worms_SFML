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

					b2CircleShape circle;
					circle.m_radius = 0.1 / SCALE;
					b2FixtureDef circleDef;
					circleDef.shape = &circle;
					circleDef.density = 0;
					circleDef.friction = 0.5f;
					circleDef.filter.categoryBits = CATEGORY_GROUND;

					circleDef.filter.maskBits = MASK_GROUND;

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
		bodyDef.position.Set(worm[i].position.x / SCALE, worm[i].position.y / SCALE);
		bodyDef.fixedRotation = true;

		body[i] = world.CreateBody(&bodyDef);		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(0.35, 0.4);		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 100.0f;
		fixtureDef.friction = 0.03f;		fixtureDef.filter.categoryBits = CATEGORY_WORMS;		fixtureDef.filter.maskBits = MASK_WORM;
		body[i]->CreateFixture(&fixtureDef);

		//Добавляем прямоугольник для определения на земле мы или нет
		dynamicBox.SetAsBox(0.8, 0.8, b2Vec2(0, -0.4), 0);
		fixtureDef.isSensor = true;
		b2Fixture* footSensorFixture = body[i]->CreateFixture(&fixtureDef);

		body[i]->SetBullet(true);

	}


};