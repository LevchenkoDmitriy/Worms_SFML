#pragma once
#ifndef RENDER_H
#define RENDER_H
//����������, ���������� �� �������� ������ ����
extern bool eventMenuRender;
//����� ���� ��������
extern bool eventGameSettingsRender;
//����� ����
extern bool eventGameStart;
//����, ���������� �� ���������� ���������
extern bool terrarianFlag;
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
extern int stars[2][400];
//������ �������� ����
extern double water;
//�������� � ������ ��� ������
extern sf::Texture wormTexture;
extern sf::Sprite wormSprite;


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
//������ ������
void wormRenderMoving();
//����������� ����� �����
void drawWormName();
//������� ��������������� �������� ��� ���������� ��������
sf::Sprite resize(sf::Sprite sprite);
//��������� ������
void drawWeapon();
//��������� ��������
void drawShot();

#endif