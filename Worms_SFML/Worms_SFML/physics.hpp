#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H
//������� �� ����������� ������� Box2D � �������
extern const float SCALE;
//������� �� ������ � �������
extern const double RAD;
//��������������� ������ ��� �������� ������ �����
extern bool groundSavePhysics[2500][1000];
//�������� ��� ������� �����
extern b2Body* body[8];

//��������� ������ �����
void groundPhysics();

void wormGeneratePhysics();
#endif