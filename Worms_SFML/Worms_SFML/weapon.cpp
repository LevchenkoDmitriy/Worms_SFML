#include <includes.hpp>

b2Body* rocket = NULL;
b2Vec2 boomCenter;
bool boom = false;
bool bullet = false;
bool contact = false;
float timer = 0;

const short CATEGORY_WORMS = 0x0001;
const short CATEGORY_ROCKET = 0x0002; 
const short CATEGORY_GROUND = 0x0003;

const short MASK_WORM = CATEGORY_WORMS;
const short MASK_ROCKET = CATEGORY_ROCKET;
const short MASK_GROUND = -1;

float rotation;
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
		rocketDef.position.Set(positionWorm.x, positionWorm.y);	rocketDef.type = b2_dynamicBody;	rocket = world.CreateBody(&rocketDef);	b2PolygonShape rocketBox;
		rocketBox.SetAsBox(0.1, 0.1);	b2FixtureDef fixtureRocketDef;
	fixtureRocketDef.shape = &rocketBox;
	fixtureRocketDef.density = 100;	fixtureRocketDef.filter.categoryBits = CATEGORY_ROCKET;	fixtureRocketDef.filter.maskBits = MASK_ROCKET;	rocket->CreateFixture(&fixtureRocketDef);		rocket->SetBullet(true);
	sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		b2Vec2 direction_new;

	direction_new.x = mousePosition.x - positionWorm.x*SCALE;
	direction_new.y = mousePosition.y - positionWorm.y*SCALE;

		rotation = (atan2(direction_new.x, direction_new.y)) * RAD - 90;
		float force = 9000;

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
		rocketSprite.setRotation(rotation*RAD);

		//Отрисовка
		window.draw(rocketSprite);
	}
}

void checkBullet() {
	if (bullet) {

		b2Vec2 pos = rocket->GetPosition();

		for (b2ContactEdge* edge = rocket->GetContactList(); edge; edge = edge->next) {
			if (edge->contact->IsTouching()) {
				contact = true;
				boom = true;
				boomCenter = pos;
				//Уничтожение ракеты
				world.DestroyBody(rocket);
				break;
			}
		}


		//Удаление в месте взрыва ландшафта и физики ландшафта
		if (contact) {
			bullet = false;
			contact = false;
			for (int i = 0; i < 2500; i++) {
				for (int j = 0; j < 1000; j++) {
					if (((i - pos.x*SCALE)*(i - pos.x*SCALE) + (j - pos.y*SCALE)*(j - pos.y*SCALE)) < 3000) {
						terrarian[i][j] = false;
						groundSavePhysics[i][j] = false;
					}
				}
			}
			//Отбрасываем червя и отнимаем жизни
			for (int i = 0; i < 8; i++) {
				b2Vec2 wormPos = body[i]->GetPosition();

				b2Vec2 direction_new;

				direction_new.x = wormPos.x*SCALE - pos.x*SCALE;
				direction_new.y = wormPos.x*SCALE - pos.x*SCALE;

				if ((direction_new.x*direction_new.x +
					(direction_new.y*direction_new.y)) < 3000) {
					float rotation = (atan2(direction_new.x, direction_new.y)) * RAD - 90;
					float module = sqrt(direction_new.x*direction_new.x + direction_new.y*direction_new.y);

					body[i]->ApplyForceToCenter(b2Vec2(module*5000*cos(rotation* PI / 180.0), module*5000* (-1)*sin(rotation* PI / 180.0)), true);
					worm[i].health -= 1/(module*0.005);
				}
			}

			//Перерасчет вывода ландшафта
			terrarianFlag = true;

			//Удаление тел
			b2Body* node = world.GetBodyList();
			while (node)
			{
				b2Body* b = node;
				if(b != NULL){
				node = node->GetNext();
				b2Vec2 bodyPosition = b->GetPosition();

				bodyPosition.x = (int)(bodyPosition.x*SCALE);
				bodyPosition.y = (int)(bodyPosition.y*SCALE);
				if(b->GetUserData() != NULL){
					int integer = (int)b->GetUserData();

					if ((groundSavePhysics[(int)bodyPosition.x][(int)bodyPosition.y] == false) &&
						(integer == 100)) {
						world.DestroyBody(b);
					}
					}
		}
	}
}
	}
}

void drawBoom() {
	if (boom) {
		sf::Texture boomTexture;
		boomTexture.loadFromFile("resource/images/weapon/boom.png");
		sf::Sprite boomSprite(boomTexture);
		boomSprite.setScale(2, 2);
		boomSprite.setPosition(boomCenter.x*SCALE, boomCenter.y*SCALE);
		boomSprite.setOrigin(20, 20);
		if (timer > 1) {
			timer = 0;
			boom = false;
		}
		else if(1 > timer > 0){
			timer += 0.05;
			window.draw(boomSprite);
		}
	}

}