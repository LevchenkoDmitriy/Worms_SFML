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
//������� ��������� ��������(��. singleRender)
extern bool eventSingleRender;
//������ ��� ����
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;
//����������� ������
extern sf::Color red, blue, white, red, green, yellow, orange, black;
//������� ����
extern bool terrarian[2500][1000];
//������ ��������� ��������
extern int stars[2][70];
//������ �������� ����
extern short water;

//������ ����
void renderMenu(bool render);
//������ ���� �������� ����
void gameSettings(bool render);
//�������� � ������ ����
void gameStart(bool start);
//����������� ���������
void drawTerrarian();
//������� ��������, ������� �� ����� �������� ���� ���������� �� ����� ����
void singleRender(bool render);
//������� ��������������� �������� ��� ���������� ��������
sf::Sprite resize(sf::Sprite sprite);

#endif