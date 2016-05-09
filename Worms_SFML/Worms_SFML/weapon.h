#pragma once
#ifndef WEAPON_H
#define WEAPON_H

class weapon {
public:
	void renderWeapon() {
		sf::Texture weaponTexture;
		weaponTexture.loadFromFile("resource/images/weapon/bazuka.png");
		sf::Sprite weaponSprite(weaponTexture);
		weaponSprite.setPosition(positionWorm.x*SCALE, positionWorm.y*SCALE);
		weaponSprite.setOrigin(20, 20);
		if (worm[currentWorm].view == true) {
			weaponSprite.setRotation(0.5 * RAD);
		}
		else {
			weaponSprite.setScale(-1, 1);
			weaponSprite.setRotation(-0.5 * RAD);
		}

		window.draw(weaponSprite);
	}

	void shot() {
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(worm[i].position.x / SCALE, worm[i].position.y / SCALE);
		bodyDef.fixedRotation = true;

		body[i] = world.CreateBody(&bodyDef);		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(0.35, 0.4);		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 100.0f;
		fixtureDef.friction = 0.03f;		body[i]->CreateFixture(&fixtureDef);

		//Добавляем прямоугольник для определения на земле мы или нет
		dynamicBox.SetAsBox(0.8, 0.8, b2Vec2(0, -0.4), 0);
		fixtureDef.isSensor = true;
		b2Fixture* footSensorFixture = body[i]->CreateFixture(&fixtureDef);

		body[i]->SetBullet(true);

	}
private:
	b2Vec2 positionWorm = body[currentWorm]->GetPosition();
};

#endif
