#pragma once
#ifndef RENDER_H
#define RENDER_H
//Переменная, отвечающая за нужность вывода меню
extern bool eventMenuRender;
//Вывод меню настроек
extern bool eventGameSettingsRender;
//Старт игры
extern bool eventGameStart;
//Флаг, отвечающий за перерендер ландшафта
extern bool terrarianFlag;
//Номер выбранной текстуры для генерации карты
extern int numOfTexture;
//Номер выбранного цвета
extern int colorChooseNumber;
//Просчет одиночных объектов(см. singleRender)
extern bool eventSingleRender;
//Задний фон меню
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;
//Определение цветов
extern sf::Color red, blue, white, red, green, yellow, orange, black;
//Игровое поле
extern bool terrarian[2500][1000];
//Массив координат звёздочек
extern int stars[2][400];
//Массив анимации воды
extern double water;
//Текстура и спрайт для червей
extern sf::Texture wormTexture;
extern sf::Sprite wormSprite;


//Рендер меню
void renderMenu(bool render);
//Рендер меню настроек игры
void gameSettings(bool render);
//Загрузка и запуск игры
void gameStart(bool start);
//Отображение ландшафта
void drawTerrarian();
//Просчёт объектов, которые не будут изменять свои координаты во время игры
void singleRender(bool render);
//Рендер червей
void wormRenderMoving();
//Отображение имени червя
void drawWormName();
//Функция масштабирования спрайтов под разрешение монитора
sf::Sprite resize(sf::Sprite sprite);
//Отрисовка оружия
void drawWeapon();
//Отрисовка выстрела
void drawShot();

#endif