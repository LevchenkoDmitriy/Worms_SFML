#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H
//Перевод из метрической системы Box2D в пиксели
extern const int SCALE;
//Перевод из радиан в градусы
extern const int RAD;
//Вспомогательный массив для хранения физики земли
extern bool groundSavePhysics[2500][1000];
//Хранение тел каждого червя
extern b2Body* body[6];

//Обработка физики земли
void groundPhysics();
//Генерация хитбоксов каждого червя
void wormGeneratePhysics();
#endif