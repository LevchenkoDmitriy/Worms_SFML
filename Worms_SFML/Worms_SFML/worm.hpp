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
	bool isJumpRight;
	bool isJumpLeft;
	bool onGround;

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
		if (worm[currentWorm].onGround) {
			worm[currentWorm].isMoveLeft = true;
			b2Vec2 position = body[currentWorm]->GetPosition();
			position.x -= 0.1;
			body[currentWorm]->SetTransform(position, 0);
			body[currentWorm]->ApplyForceToCenter(b2Vec2(0, 0.1), true);
		}
		else {
			b2Vec2 position = body[currentWorm]->GetPosition();
			position.x -= 0.08;
			body[currentWorm]->SetTransform(position, 0);
			body[currentWorm]->ApplyForceToCenter(b2Vec2(0, 0.1), true);
		}
	}
	void wormMoveRight() {
		if (worm[currentWorm].onGround) {
			worm[currentWorm].isMoveRight = true;
			b2Vec2 position = body[currentWorm]->GetPosition();
			position.x += 0.1;
			body[currentWorm]->SetTransform(position, 0);
			body[currentWorm]->ApplyForceToCenter(b2Vec2(0, 0.1), true);
		}
		else
		{
			b2Vec2 position = body[currentWorm]->GetPosition();
			position.x += 0.08;
			body[currentWorm]->SetTransform(position, 0);
			body[currentWorm]->ApplyForceToCenter(b2Vec2(0, 0.1), true);
		}
	}

	void wormJump() {
		if (worm[currentWorm].onGround) {
			worm[currentWorm].isJump = true;
			body[currentWorm]->ApplyForceToCenter(b2Vec2(0, -150000), true);
		}
	}

	void wormJumpRight() {
		if (worm[currentWorm].onGround) {
			worm[currentWorm].isJumpRight = true;
			body[currentWorm]->ApplyForceToCenter(b2Vec2(-50000, -50000), true);
		}
	}

	void wormJumpLeft() {
		if (worm[currentWorm].onGround) {
			worm[currentWorm].isJumpLeft = true;
			body[currentWorm]->ApplyForceToCenter(b2Vec2(50000, -50000), true);
		}
	}

};

class wormRender {
public:
	void wormMovingLeftRender() {
		moveTimerLeft += 0.4;
		if (moveTimerLeft > 1) {
			if (leftX == 2)
				leftX = 0;
			else
				leftX++;
				wormSprite.setTextureRect(sf::IntRect(leftX * 40, 0, 40, 40));
				wormSprite.setOrigin(20, 20);
				wormSprite.setPosition(position.x*SCALE, position.y*SCALE);
				wormSprite.setRotation(angle*RAD);

				window.draw(wormSprite);
			moveTimerLeft = 0;
		}
	}

	void wormMovingRightRender() {
		moveTimerRight += 0.4;
		if (moveTimerRight > 1) {
			if (rightX == 2)
				rightX = 0;
			else
				rightX++;
			wormSprite.setTextureRect(sf::IntRect(rightX * 40, 40, 40, 40));
			wormSprite.setOrigin(20, 20);
			wormSprite.setPosition(position.x*SCALE, position.y*SCALE);
			wormSprite.setRotation(angle*RAD);

			window.draw(wormSprite);
			moveTimerRight = 0;
		}
	}

	void wormJumpRender() {
			if (!worm[currentWorm].onGround) {
				wormSprite.setTextureRect(sf::IntRect(80, 80, 40, 60));
				wormSprite.setOrigin(20, 20);
				wormSprite.setPosition(position.x*SCALE, position.y*SCALE);
				wormSprite.setRotation(angle*RAD);

				window.draw(wormSprite);
		}
	}

	void wormStaticCurrentRender() {
		b2Vec2 positionStatic;
		positionStatic = body[currentWorm]->GetPosition();
		if (worm[currentWorm].view == false) {
			wormSprite.setTextureRect(sf::IntRect(leftX*40, 0, 40, 40));
			wormSprite.setOrigin(20, 20);
			wormSprite.setPosition(positionStatic.x*SCALE, positionStatic.y*SCALE);
			window.draw(wormSprite);
		}
		if (worm[currentWorm].view == true) {
			wormSprite.setTextureRect(sf::IntRect(rightX * 40, 40, 40, 40));
			wormSprite.setOrigin(20, 20);
			wormSprite.setPosition(positionStatic.x*SCALE, positionStatic.y*SCALE);
			window.draw(wormSprite);
		}
	}
	
	void wormRenderStatic() {
		b2Vec2 positionStatic;
		for (int i = 0; i < 6; i++) {
			if (!worm[i].isDead && worm[i].onGround) {
				if (i == currentWorm)
					continue;
				else {
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
			else
				if (!worm[i].onGround && !worm[i].isDead) {
					positionStatic = body[i]->GetPosition();
					wormSprite.setTextureRect(sf::IntRect(80, 80, 40, 60));
					wormSprite.setOrigin(20, 20);
					wormSprite.setPosition(positionStatic.x*SCALE, positionStatic.y*SCALE);
					wormSprite.setRotation(angle*RAD);

					window.draw(wormSprite);
				}
		}
	}


private:
	b2Vec2 position = body[currentWorm]->GetPosition();
	float angle = body[currentWorm]->GetAngle();
};

void checkGround();
void setGround();

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}

#endif