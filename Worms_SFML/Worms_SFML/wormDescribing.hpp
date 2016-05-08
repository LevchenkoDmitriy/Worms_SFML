#pragma once
#ifndef WORMHANDLING_H
#define WORMHANDLING_H
#include "includes.hpp"


class Worm {
public:
	float x, y, w, h, dx, dy, speed; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir; //направление (direction) движения игрока
	sf::String File; //файл с расширением
	sf::Image image;
	sf::Texture wormTexture;//сфмл текстура
	sf::Sprite wormSprite;//сфмл спрайт

	Worm(sf::String F, float X, float Y, float W, float H) { //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		dx = 0; dy = 0; speed = 0; dir = 0;
		File = F;//имя файла+расширение
		w = W; h = H;//высота и ширина
		image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");
		wormTexture.loadFromFile("resource/images/worms/worms.png");
		wormSprite.setTexture(wormTexture);//заливаем спрайт текстурой
		x = X; y = Y;//координата появления спрайта
		wormSprite.setTextureRect(sf::IntRect(0, 0, w, h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
	}
	void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
		{
		case 0: dx = speed; dy = 0; break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
		case 1: dx = -speed; dy = 0; break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
		case 2: dx = 0; dy = speed; break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
		case 3: dx = 0; dy = -speed; break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
		}

		x += dx*time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
		y += dy*time;//аналогично по игреку

		speed = 0;//зануляем скорость, чтобы персонаж остановился.
		wormSprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	}

	void wormGeneratePhysics() {
		for (int i = 0; i < 6; i++) {
			b2BodyDef bodyDef;
			bodyDef.type = b2_dynamicBody;
			bodyDef.position.Set(worm[i].position.x / SCALE, worm[i].position.y / SCALE);
			bodyDef.fixedRotation = true;

			body[i] = world.CreateBody(&bodyDef);			b2PolygonShape dynamicBox;
			dynamicBox.SetAsBox(0.4, 0.45);			b2FixtureDef fixtureDef;
			fixtureDef.shape = &dynamicBox;
			fixtureDef.density = 100.0f;
			fixtureDef.friction = 0.03f;			body[i]->CreateFixture(&fixtureDef);

			//Добавляем прямоугольник для определения на земле мы или нет
			dynamicBox.SetAsBox(0.3, 0.3, b2Vec2(0, -0.45), 0);
			fixtureDef.isSensor = true;
			b2Fixture* footSensorFixture = body[i]->CreateFixture(&fixtureDef);
			footSensorFixture->SetUserData((void*)i);


		}


};
};

#endif