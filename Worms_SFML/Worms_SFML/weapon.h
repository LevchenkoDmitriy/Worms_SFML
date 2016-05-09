#pragma once
#ifndef WEAPON_H
#define WEAPON_H

extern b2Body* rocket;
extern bool shot;

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
		bodyDef.position.Set(positionWorm.x * SCALE, positionWorm.y * SCALE);

		rocket = world.CreateBody(&bodyDef);		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(0.35, 0.4);		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 100.0f;
		fixtureDef.friction = 0.03f;		rocket->CreateFixture(&fixtureDef);

		rocket->SetBullet(true);
	}

	void renderRocket() {
		b2Vec2 rocketPosition = rocket->GetPosition();
		float angle = rocket->GetAngle();
		sf::Texture weaponTexture;
		weaponTexture.loadFromFile("resource/images/weapon/raketa.png");
		sf::Sprite weaponSprite(weaponTexture);
		weaponSprite.setPosition(rocketPosition.x*SCALE, rocketPosition.y*SCALE);
		weaponSprite.setOrigin(20, 20);


	}
private:
	b2Vec2 positionWorm = body[currentWorm]->GetPosition();
};

void weaponShot();

#endif
