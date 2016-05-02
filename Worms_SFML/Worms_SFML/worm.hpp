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

	bool isMoveLeft;
	bool isMoveRight;
	bool isJump;
	bool isFalling;
};
//Класс обработки движения


extern wormFields *worm;
//Указатель на текущего червя
extern int currentWorm;

//Генерация червей игрока
void generateWorms();

class wormMoving {
public:
	void wormMoveLeft() {
		worm[currentWorm].isMoveLeft = true;
		worm[currentWorm].position.x -= 10 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width);
		worm[currentWorm].isMoveLeft = false;
	}
	void wormMoveRight() {
		worm[currentWorm].isMoveRight = true;
		worm[currentWorm].position.x += 10 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width);
		worm[currentWorm].isMoveRight = false;
	}
	void wormJumpLeft() {
		/*worm[currentWorm].isJumpLeft = true;
		worm[currentWorm].isJumpLeft = false;*/
	}
	void wormJumpRight() {
		/*worm[currentWorm].isJumpRight = true;
		worm[currentWorm].isJumpRight = false;*/
	}

	void wormJump() {
		/*	worm[currentWorm].isJump = true;
		worm[currentWorm].isJump = false;*/
	}

	void wormFall() {

	}
};

#endif