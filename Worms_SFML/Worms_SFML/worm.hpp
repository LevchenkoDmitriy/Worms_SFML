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

	bool isMoveLeft;
	bool isMoveRight;
	bool isJump;
	bool isFalling;
};

extern wormFields *worm;
//��������� ������ ������
void generateWorms();

#endif