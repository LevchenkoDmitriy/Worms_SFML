#pragma once
#ifndef MAIN_H
#define MAIN_H
//������ ����
extern sf::RenderWindow window;
//������ ����������
extern b2Vec2 gravity;
//������� ����
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
//����� �� ����
extern bool quit;

//�������� ���� ��� Box2D
void box2dWorldInit();
//��������� �������
void Handler();

#endif