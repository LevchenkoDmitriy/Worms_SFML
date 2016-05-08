#pragma once
#ifndef WORM_H
#define WORM_H
//Описание червей
struct wormFields {
	int numberOfWorm;
	bool isDead;
	sf::Vector2f position;
	int health;
	int team;
	float angle;

	bool isMoveLeft;
	bool isMoveRight;
	bool isJump;
	bool isFalling;

	bool view;//Показывает, куда двигался червь(нужно для статичного рендера)
};
//Класс обработки движения
extern wormFields *worm;
//Указатель на текущего червя
extern int currentWorm;
//Функция проверки смерти червя, при выходе за границу обсчета физики
void deathChecking();
//Генерация червей игрока
void generateWorms();
//Переменные управления анимацией
extern int leftX;
extern int rightX;
extern double moveTimerLeft;
extern double moveTimerRight;
//Управление движением червяка
class wormMoving {
public:
	void wormMoveLeft() {
		worm[currentWorm].isMoveLeft = true;
		float angle = body[currentWorm]->GetAngle();
		body[currentWorm]->ApplyLinearImpulse(b2Vec2(-700, 0), body[currentWorm]->GetLocalCenter(), true);
	}
	void wormMoveRight() {
		worm[currentWorm].isMoveRight = true;
		body[currentWorm]->ApplyLinearImpulse(b2Vec2(+700, 0), body[currentWorm]->GetLocalCenter(), true);
	}

	void wormJump() {
			worm[currentWorm].isJump = true;
			body[currentWorm]->ApplyLinearImpulse(b2Vec2(0, -1000), body[currentWorm]->GetLocalCenter(), true);
		//worm[currentWorm].isJump = false;
	}

	void wormFall() {

	}
};

class wormRender {
public:
	void wormMovingLeftRender() {
		moveTimerLeft += 0.5;
		if (moveTimerLeft > 1) {
			if (leftX == 3)
				leftX = 0;
			else
				leftX++;
			for (int i = 0; i < 3; i++) {
				wormSprite.setTextureRect(sf::IntRect(leftX * 40, 0, 40, 40));
				wormSprite.setOrigin(20, 20);
				wormSprite.setPosition(position.x*SCALE, position.y*SCALE);
				wormSprite.setRotation(angle*RAD);

				window.draw(wormSprite);
			}
			moveTimerLeft = 0;
		}
	}

	void wormMovingRightRender() {
		moveTimerRight += 0.5;
		if (moveTimerRight > 1) {
			if (rightX == 3)
				rightX = 0;
			else
				rightX++;
			for (int i = 0; i < 3; i++) {
				wormSprite.setTextureRect(sf::IntRect(rightX * 40, 40, 40, 40));
				wormSprite.setOrigin(20, 20);
				wormSprite.setPosition(position.x*SCALE, position.y*SCALE);
				wormSprite.setRotation(angle*RAD);

				window.draw(wormSprite);
			}
			moveTimerRight = 0;
		}
	}

	void wormStaticCurrentRender() {
		b2Vec2 positionStatic;
		positionStatic = body[currentWorm]->GetPosition();
		if (worm[currentWorm].view == false) {
			wormSprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
			wormSprite.setOrigin(20, 20);
			wormSprite.setPosition(positionStatic.x*SCALE, positionStatic.y*SCALE);
			window.draw(wormSprite);
		}
		if (worm[currentWorm].view == true) {
			wormSprite.setTextureRect(sf::IntRect(0, 40, 40, 40));
			wormSprite.setOrigin(20, 20);
			wormSprite.setPosition(positionStatic.x*SCALE, positionStatic.y*SCALE);
			window.draw(wormSprite);
		}
	}
	
	void wormRenderStatic() {
		b2Vec2 positionStatic;
		for (int i = 0; i < 6; i++) {
			if (!worm[i].isDead) {
				if (i == currentWorm)
					continue;
				else{
				positionStatic = body[i]->GetPosition();
				if (worm[i].view == false) {
					wormSprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
					wormSprite.setOrigin(20, 20);
					wormSprite.setPosition(positionStatic.x*SCALE, positionStatic.y*SCALE);
					window.draw(wormSprite);
				}
				if (worm[i].view == true) {
					wormSprite.setTextureRect(sf::IntRect(0, 40, 40, 40));
					wormSprite.setOrigin(20, 20);
					wormSprite.setPosition(positionStatic.x*SCALE, positionStatic.y*SCALE);
					window.draw(wormSprite);
				}
				}
			}
		}
	}


private:
	b2Vec2 position = body[currentWorm]->GetPosition();
	float angle = body[currentWorm]->GetAngle();
};

#endif