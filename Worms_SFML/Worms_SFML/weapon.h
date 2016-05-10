#pragma once
#ifndef WEAPON_H
#define WEAPON_H

//Тело ракеты
extern b2Body* rocket;
//Переменная, отвечающая за выстрел
extern bool bullet;
//Битовые маски для сравнения коллизий
extern const short CATEGORY_WORMS;
extern const short CATEGORY_ROCKET;
extern const short CATEGORY_GROUND;

extern const short MASK_WORM;
extern const short MASK_ROCKET;
extern const short MASK_GROUND;

void renderWeapon();
//Совершение выстрела
void shot();
//Отсовка ракеты
void renderBullet();
//Проверки для ракеты
void checkBullet();

#endif
