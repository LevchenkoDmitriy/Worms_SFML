#include <includes.hpp>

b2Body* rocket;
bool bullet = false;

const short CATEGORY_WORMS = 0x0001;
const short CATEGORY_ROCKET = 0x0002; 
const short CATEGORY_GROUND = 0x0003;

const short MASK_WORM = CATEGORY_ROCKET;
const short MASK_ROCKET = 0;
const short MASK_GROUND = -1;

void renderWeapon() {
	b2Vec2 positionWorm = body[currentWorm]->GetPosition();

	sf::Texture weaponTexture;
	weaponTexture.loadFromFile("resource/images/weapon/bazuka.png");
	sf::Sprite weaponSprite(weaponTexture);

	weaponSprite.setPosition(positionWorm.x*SCALE, positionWorm.y*SCALE);
	weaponSprite.setOrigin(20, 20);

	//������ � ����������� �� ����������� �������
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
	b2Vec2 positionWorm = body[currentWorm]->GetPosition();

	b2BodyDef rocketDef;
	if (worm[currentWorm].view) {
		rocketDef.position.Set(positionWorm.x, positionWorm.y);	}else		rocketDef.position.Set(positionWorm.x, positionWorm.y);	rocketDef.type = b2_dynamicBody;	rocket = world.CreateBody(&rocketDef);	b2PolygonShape rocketBox;
	rocketBox.SetAsBox(0.3, 0.3);	b2FixtureDef fixtureRocketDef;
	fixtureRocketDef.shape = &rocketBox;
	fixtureRocketDef.density = 0.0015;
	fixtureRocketDef.friction = 0.3f;	fixtureRocketDef.filter.categoryBits = CATEGORY_ROCKET;	fixtureRocketDef.filter.maskBits = MASK_ROCKET;	rocket->CreateFixture(&fixtureRocketDef);
	sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	b2Vec2 direction, direction_new;

	direction_new.x = mousePosition.x*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width) - positionWorm.x*SCALE;
	direction_new.y = mousePosition.y*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height) - positionWorm.y*SCALE;

	float rotation = (atan2(direction_new.x, direction_new.y)) * RAD - 90;

	printf("%f\n", rotation);

	rocket->ApplyForceToCenter(b2Vec2(cos(rotation* PI / 180.0), (-1)*sin(rotation* PI / 180.0)), true);

	bullet = true;


}

void renderBullet() {
	if (bullet) {
		//���������� �������� � ������ ��� ���������
		sf::Texture rocketTexture;
		rocketTexture.loadFromFile("resource/images/weapon/rocket.png");
		sf::Sprite rocketSprite(rocketTexture);
		rocketSprite.setOrigin(20, 20);

		//�������� �������������� � ���� ������� ������
		b2Vec2 bulletPos = rocket->GetPosition();
		float angle = rocket->GetAngle();

		//����������� ���������� �������
		rocketSprite.setPosition(bulletPos.x * SCALE, bulletPos.y * SCALE);
		rocketSprite.setRotation(angle*RAD);

		//���������
		window.draw(rocketSprite);
	}
}

void checkBullet() {

}