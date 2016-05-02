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
//������� ������ � ������� �������� ����
extern sf::Clock elapsedTime;

extern b2World world;

//��������� �������
void Handler();

#endif