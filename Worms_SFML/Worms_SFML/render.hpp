#pragma once
#ifndef RENDER_H
#define RENDER_H
//Переменная, отвечающая за нужность вывода меню
extern bool eventMenuRender;
//Вывод меню настроек
extern bool eventGameSettingsRender;
//Старт игры
extern bool eventGameStart;
//Номер выбранной текстуры для генерации карты
extern int numOfTexture;
//Номер выбранного цвета
extern int colorChooseNumber;
//Задний фон меню
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;
//Определение цветов
extern sf::Color red, blue, white, red, green, yellow, orange, black;
//Игровое поле
extern bool terrarian[2500][1000];

//Рендер меню
void renderMenu(bool render);
//Рендер меню настроек игры
void gameSettings(bool render);
//Загрузка и запуск игры
void gameStart(bool start);
//Отображение ландшафта
void drawTerrarian();

#endif