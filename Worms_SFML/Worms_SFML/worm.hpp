#pragma once
#ifndef WORM_H
#define WORM_H
//�������� ������
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
	bool isJumpLeft;
	bool isJumpRight;
};
//����� ��������� ��������
extern wormFields *worm;
//��������� �� �������� �����
extern int currentWorm;

//��������� ������ ������
void generateWorms();
void deathChecking();
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
	void wormJumpLeft() {
		worm[currentWorm].isJumpLeft = true;
		body[currentWorm]->ApplyLinearImpulse(b2Vec2(-300, -800), body[currentWorm]->GetLocalCenter(), true);
		//worm[currentWorm].isJumpLeft = false;
	}
	void wormJumpRight() {
		worm[currentWorm].isJumpRight = true;
		body[currentWorm]->ApplyLinearImpulse(b2Vec2(300, -800), body[currentWorm]->GetLocalCenter(), true);
		//worm[currentWorm].isJumpRight = false;
	}

	void wormJump() {
			worm[currentWorm].isJump = true;
			body[currentWorm]->ApplyLinearImpulse(b2Vec2(0, -1000), body[currentWorm]->GetLocalCenter(), true);
		//worm[currentWorm].isJump = false;
	}

	void wormFall() {

	}
};

#endif