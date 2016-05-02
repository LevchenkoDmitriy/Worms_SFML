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
					groundBodyDef.position.Set(i/SCALE, j/SCALE);					b2Body* groundBody = world.CreateBody(&groundBodyDef);					b2PolygonShape groundBox;
					groundBox.SetAsBox(0.001/SCALE, 0.001 / SCALE);					groundBody->CreateFixture(&groundBox, 0.0f);
				}
			}
		}
	}
}

void debugDraw() {
	sf::Texture boxTexture;
	boxTexture.loadFromFile("box.png");
	sf::Sprite box(boxTexture);
	box.setOrigin(45.0f, 45.0f);
	box.setScale(0.1, 0.1);
	for (int i = 0; i < 2500; i++) {
		for (int j = 0; j < 1000; j++) {
			if (groundSavePhysics[i][j] == true) {
				box.setPosition(i, j);
				window.draw(box);
			}
				
		}
	}
			
}