#include <includes.hpp>

b2Body* rocket;
bool bullet = false;

const short CATEGORY_WORMS = 0x0001;
const short CATEGORY_ROCKET = 0x0002; 
const short CATEGORY_GROUND = 0x0003;

const short MASK_WORM = CATEGORY_WORMS;
const short MASK_ROCKET = CATEGORY_ROCKET;
const short MASK_GROUND = -1;

void renderWeapon() {
	b2Vec2 positionWorm = body[currentWorm]->GetPosition();

	sf::Texture weaponTexture;
	weaponTexture.loadFromFile("resource/images/weapon/bazuka.png");
	sf::Sprite weaponSprite(weaponTexture);

	weaponSprite.setPosition(positionWorm.x*SCALE, positionWorm.y*SCALE);
	weaponSprite.setOrigin(20, 20);

	//Рендер в зависимости от направления взгляда
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
	rocketBox.SetAsBox(0.2, 0.2);	b2FixtureDef fixtureRocketDef;
	fixtureRocketDef.shape = &rocketBox;
	fixtureRocketDef.density = 10;	fixtureRocketDef.filter.categoryBits = CATEGORY_ROCKET;	fixtureRocketDef.filter.maskBits = MASK_ROCKET;	rocket->CreateFixture(&fixtureRocketDef);
	sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	b2Vec2 direction, direction_new;

	direction_new.x = mousePosition.x - positionWorm.x*SCALE;
	direction_new.y = mousePosition.y - positionWorm.y*SCALE;

	float rotation = (atan2(direction_new.x, direction_new.y)) * RAD - 90;
	float force = 5000;

	rocket->ApplyForceToCenter(b2Vec2(force*cos(rotation* PI / 180.0), force * (-1)*sin(rotation* PI / 180.0)), true);

	bullet = true;


}

void renderBullet() {
	if (bullet) {
		//Определяем текстуру и спрайт для отрисовки
		sf::Texture rocketTexture;
		rocketTexture.loadFromFile("resource/images/weapon/rocket.png");
		sf::Sprite rocketSprite(rocketTexture);
		rocketSprite.setOrigin(20, 20);

		//Получаем местоположение и угол наклона ракеты
		b2Vec2 bulletPos = rocket->GetPosition();
		float angle = rocket->GetAngle();

		//Присваиваем координаты спрайту
		rocketSprite.setPosition(bulletPos.x * SCALE, bulletPos.y * SCALE);
		rocketSprite.setRotation(angle*RAD);

		//Отрисовка
		window.draw(rocketSprite);
	}
}

void checkBullet() {

}