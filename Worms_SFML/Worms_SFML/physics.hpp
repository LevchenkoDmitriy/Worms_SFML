#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H
//������� �� ����������� ������� Box2D � �������
extern const int SCALE;
//������� �� ������ � �������
extern const int RAD;
//��������������� ������ ��� �������� ������ �����
extern bool groundSavePhysics[2500][1000];
void debugDraw();

void groundPhysics();
#endif