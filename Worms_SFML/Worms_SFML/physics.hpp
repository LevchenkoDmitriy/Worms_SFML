#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H
//������� �� ����������� ������� Box2D � �������
extern const int SCALE;
//������� �� ������ � �������
extern const int RAD;
//��������������� ������ ��� �������� ������ �����
extern bool groundSavePhysics[2500][1000];
//�������� ��� ������� �����
extern b2Body* body[6];

//��������� ������ �����
void groundPhysics();
//��������� ��������� ������� �����
void wormGeneratePhysics();
#endif