#pragma once
#ifndef MAIN_H
#define MAIN_H
//Рендер окна
extern sf::RenderWindow window;
//Вектор гравитации
extern b2Vec2 gravity;
//Размеры окна
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
//Выход из игры
extern bool quit;

//Создание мира для Box2D
void box2dWorldInit();
//Обработка нажатий
void Handler();

#endif