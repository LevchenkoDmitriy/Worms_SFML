#pragma once
#ifndef RENDER_H
#define RENDER_H
//����������, ���������� �� �������� ������ ����
extern bool eventMenuRender;
//����� ���� ��������
extern bool eventGameSettingsRender;
//����� �������� ��� �����������
extern int numOfTexture;
//������ ��� ����
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;

//������ ����
void renderMenu(bool render);
//������ ���� �������� ����
void gameSettings(bool render);

#endif