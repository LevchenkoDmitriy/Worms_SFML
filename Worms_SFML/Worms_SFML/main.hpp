#pragma once
#ifndef MAIN_H
#define MAIN_H
extern sf::ContextSettings settings;

//Рендер окна
extern sf::RenderWindow window;
//Вектор гравитации
extern b2Vec2 gravity;
//Размеры окна
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
//Выход из игры
extern bool quit;
//Времени прошло с момента открытия игры
extern sf::Clock elapsedTime;

extern b2World world;

//Обработка нажатий
void Handler();

#endif