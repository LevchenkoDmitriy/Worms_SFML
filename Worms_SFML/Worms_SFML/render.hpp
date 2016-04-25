#pragma once
#ifndef RENDER_H
#define RENDER_H
//����������, ���������� �� �������� ������ ����
extern bool eventMenuRender;
//����� ���� ��������
extern bool eventGameSettingsRender;
//����� ����
extern bool eventGameStart;
//����� ��������� �������� ��� ��������� �����
extern int numOfTexture;
//����� ���������� �����
extern int colorChooseNumber;
//������ ��� ����
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;
//����������� ������
extern sf::Color red, blue, white, red, green, yellow, orange, black;
//������� ����
extern bool terrarian[2500][1000];

//������ ����
void renderMenu(bool render);
//������ ���� �������� ����
void gameSettings(bool render);
//�������� � ������ ����
void gameStart(bool start);
//����������� ���������
void drawTerrarian();

#endif