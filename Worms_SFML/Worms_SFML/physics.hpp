#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H
//ѕеревод из метрической системы Box2D в пиксели
extern const int SCALE;
//ѕеревод из радиан в градусы
extern const int RAD;
//¬спомогательный массив дл€ хранени€ физики земли
extern bool groundSavePhysics[2500][1000];
void debugDraw();

void groundPhysics();
#endif