#pragma once
#ifndef WEAPON_H
#define WEAPON_H

//���� ������
extern b2Body* rocket;
//����������, ���������� �� �������
extern bool bullet;
//������� ����� ��� ��������� ��������
extern const short CATEGORY_WORMS;
extern const short CATEGORY_ROCKET;
extern const short CATEGORY_GROUND;

extern const short MASK_WORM;
extern const short MASK_ROCKET;
extern const short MASK_GROUND;

void renderWeapon();
//���������� ��������
void shot();
//������� ������
void renderBullet();
//�������� ��� ������
void checkBullet();

#endif
