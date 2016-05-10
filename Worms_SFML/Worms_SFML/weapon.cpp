#include <includes.hpp>

b2Body* rocket;
bool bullet = false;
bool contact = false;

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
	contact = false;
	b2Vec2 positionWorm = body[currentWorm]->GetPosition();

	b2BodyDef rocketDef;
	if (worm[currentWorm].view) {
		rocketDef.position.Set(positionWorm.x, positionWorm.y);	}else		rocketDef.position.Set(positionWorm.x, positionWorm.y);	rocketDef.type = b2_dynamicBody;	rocket = world.CreateBody(&rocketDef);	b2PolygonShape rocketBox;
	rocketBox.SetAsBox(0.01, 0.01);	b2FixtureDef fixtureRocketDef;
	fixtureRocketDef.shape = &rocketBox;
	fixtureRocketDef.density = 100;	fixtureRocketDef.filter.categoryBits = CATEGORY_ROCKET;	fixtureRocketDef.filter.maskBits = MASK_ROCKET;	rocket->CreateFixture(&fixtureRocketDef);
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
	if (bullet) {
		for (b2ContactEdge* edge = rocket->GetContactList(); edge; edge = edge->next) {
			if (edge->contact->IsTouching()) {
				contact = true;
				break;
			}
		}

		b2Vec2 pos = rocket->GetPosition();

		//Удаление в месте взрыва ландшафта и физики ландшафта
		if (contact) {
			bullet = false;
			contact = false;
			for (int i = 0; i < 2500; i++) {
				for (int j = 0; j < 1000; j++) {
					if (((i - pos.x*SCALE)*(i - pos.x*SCALE) + (j - pos.y*SCALE)*(j - pos.y*SCALE)) < 1000) {
						terrarian[i][j] = false;
						groundSavePhysics[i][j] = false;
					}
				}
			}
			//Перерасчет вывода ландшафта
			terrarianFlag = true;

			//Удаление тел
			b2Body* node = world.GetBodyList();
			while (node)
			{
				b2Body* b = node;
				node = node->GetNext();
				b2Vec2 bodyPosition = b->GetPosition();

				bodyPosition.x = bodyPosition.x*SCALE;
				bodyPosition.y = bodyPosition.y*SCALE;

				int integer = (int)b->GetUserData();
				if ((groundSavePhysics[(int)bodyPosition.x][(int)bodyPosition.y] == false) && 
					(integer == 100)) {
					world.DestroyBody(b);
				}
			}
		}
	}
}