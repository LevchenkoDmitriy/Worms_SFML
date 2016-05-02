#include "includes.hpp"

bool groundSavePhysics[2500][1000] = { false };
const int SCALE = 30.0f;
const int RAD = 57.2958;

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
					groundBodyDef.position.Set(i*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width)/SCALE,						j*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height)/SCALE);					b2Body* groundBody = world.CreateBody(&groundBodyDef);					b2PolygonShape boxPolygon;					b2CircleShape circle;					circle.m_radius = 0.01/SCALE;					boxPolygon.SetAsBox(10 / SCALE, 10 / SCALE);					groundBody->CreateFixture(&circle, 0.0f);
				}
			}
		}
	}
}