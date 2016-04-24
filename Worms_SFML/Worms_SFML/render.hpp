#pragma once
#ifndef RENDER_H
#define RENDER_H
//Переменная, отвечающая за нужность вывода меню
extern bool eventMenuRender;
//Вывод меню настроек
extern bool eventGameSettingsRender;
//Номер выбранной текстуры для генерации карты
extern int numOfTexture;
//Номер выбранного цвета
extern int colorChooseNumber;
//Задний фон меню
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;
//Определение цветов
extern sf::Color red, blue, white, red, green, yellow, orange;

//Рендер меню
void renderMenu(bool render);
//Рендер меню настроек игры
void gameSettings(bool render);

#endif