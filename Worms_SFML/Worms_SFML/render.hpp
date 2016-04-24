#pragma once
#ifndef RENDER_H
#define RENDER_H
//Переменная, отвечающая за нужность вывода меню
extern bool eventMenuRender;
//Вывод меню настроек
extern bool eventGameSettingsRender;
//Номер текстуры для отображения
extern int numOfTexture;
//Задний фон меню
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;

//Рендер меню
void renderMenu(bool render);
//Рендер меню настроек игры
void gameSettings(bool render);

#endif