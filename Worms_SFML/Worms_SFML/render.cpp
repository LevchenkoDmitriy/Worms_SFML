#include "includes.hpp"

bool eventMenuRender = true;
bool eventGameSettingsRender = false;
bool eventGameStart = false;
bool eventSingleRender = true;
bool terrarianFlag = true;

int numOfTexture = 0;
int colorChooseNumber = 0;

bool terrarian[2500][1000] = { 0 };
int stars[2][70] = { 0 };
double water = 1;
int waterTime = 0;

sf::Texture wormTexture;
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;
sf::Sprite wormSprite;
sf::Image terrarianImage;

sf::Color black = sf::Color::Black;
sf::Color white = sf::Color::White;
sf::Color red = sf::Color::Red;
sf::Color green = sf::Color::Green;
sf::Color blue = sf::Color::Blue;
sf::Color yellow = sf::Color::Yellow;
sf::Color orange(255, 160, 0);


void renderMenu(bool render) {
	if (render) {
		//Загрузка шрифтов
		sf::Font font;
		font.loadFromFile("resource/fonts/AdLib.ttf");

		//Фоновая картинка меню
		backgroundTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
		backgroundTexture.loadFromFile("resource/images/menu/backgroundMenu.png");

		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width,
			WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height);

		backgroundSprite.setPosition(sf::Vector2f(0, 0));
		window.draw(backgroundSprite);

		//Пункты меню
		sf::Text menuButton[4];
		sf::Vector2f menuPosition[4];
		//Минутка индусского кода :\, черт знает как нормально инициализировать
		menuPosition[0].x = (float)(WINDOW_WIDTH / 2 - WINDOW_WIDTH / 20);
		menuPosition[0].y = (float)(WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 20);
		menuPosition[1].x = (float)(WINDOW_WIDTH / 2 - 1.3*WINDOW_WIDTH / 20);
		menuPosition[1].y = (float)(WINDOW_HEIGHT / 2 + 3 * WINDOW_HEIGHT / 20);
		menuPosition[2].x = (float)(WINDOW_WIDTH / 2 - 1.3*WINDOW_WIDTH / 20);
		menuPosition[2].y = (float)(WINDOW_HEIGHT / 2 + 5 * WINDOW_HEIGHT / 20);
		menuPosition[3].x = (float)(WINDOW_WIDTH / 2 - 0.8*WINDOW_WIDTH / 20);
		menuPosition[3].y = (float)(WINDOW_HEIGHT / 2 + 7 * WINDOW_HEIGHT / 20);

		for (int i = 0; i < 4; i++) {
			menuButton[i].setFont(font);
			menuButton[i].setCharacterSize(WINDOW_WIDTH / 33);
		}

		menuButton[0].setString("Start");
		menuButton[1].setString("Options");
		menuButton[2].setString("Credits");
		menuButton[3].setString("Exit");

		//Проверка наведения мыши
		for (int i = 0; i < 4; i++) {
			if (sf::IntRect(menuPosition[i].x, menuPosition[i].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))) {
				menuButton[i].setColor(sf::Color(255, 0, 0, 255));
				menuButton[i].setCharacterSize(WINDOW_WIDTH / 30);
			}
		}

		//Проверка нажатий на кнопки
		//Start
		if (sf::IntRect(menuPosition[0].x, menuPosition[0].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			eventMenuRender = false;
			eventGameSettingsRender = true;
		}

		if (sf::IntRect(menuPosition[3].x, menuPosition[3].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			quit = true;
		}

		for (int i = 0; i < 4; i++) {
			menuButton[i].setPosition(menuPosition[i]);
			window.draw(menuButton[i]);
		}
	}
}

void gameSettings(bool render) {
	if (render) {
		//Количество текстур для карт
		const int N = 2;

		//Загрузка шрифтов
		sf::Font font;
		font.loadFromFile("resource/fonts/AdLib.ttf");

		//Фоновая картинка меню
		backgroundTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
		backgroundTexture.loadFromFile("resource/images/menu/backgroundMenu.png");

		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width,
			WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height);

		backgroundSprite.setPosition(sf::Vector2f(0, 0));
		window.draw(backgroundSprite);

		//Пункты меню
		sf::Text menuButton[2];
		sf::Text colorChoose[7];
		sf::Vector2f menuPosition[7 + N];
		sf::Texture Arrows[2];
		sf::Texture Textures[N];
		sf::Sprite menuElements[N + 2];


		//Минутка индусского кода :\, черт знает как нормально инициализировать
			//Надписи Start и Back
		menuPosition[0].x = (float)(WINDOW_WIDTH / 2 - 1.7*WINDOW_WIDTH / 20);
		menuPosition[0].y = (float)(WINDOW_HEIGHT / 2 + 6 * WINDOW_HEIGHT / 20);
		menuPosition[1].x = (float)(WINDOW_WIDTH / 2 - 0.8*WINDOW_WIDTH / 20);
		menuPosition[1].y = (float)(WINDOW_HEIGHT / 2 + 8 * WINDOW_HEIGHT / 20);
			//Позиции верхних стрелок
		menuPosition[2].x = (float)(WINDOW_WIDTH / 2 - 2.2*WINDOW_WIDTH / 20);
		menuPosition[2].y = (float)(WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 20);
		menuPosition[3].x = (float)(WINDOW_WIDTH / 2 + 1.2*WINDOW_WIDTH / 20);
		menuPosition[3].y = (float)(WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 20);
			//Позиция текстуры
		menuPosition[4].x = (float)(WINDOW_WIDTH / 2 - 0.5*WINDOW_WIDTH / 20);
		menuPosition[4].y = (float)(WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 20);
			//Позиция цвета
		menuPosition[5].x = (float)(WINDOW_WIDTH / 2 - 0.6*WINDOW_WIDTH / 20);
		menuPosition[5].y = (float)(WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 5);
		//Позиция нижних стрелок
		menuPosition[6].x = (float)(WINDOW_WIDTH / 2 - 2.2*WINDOW_WIDTH / 20);
		menuPosition[6].y = (float)(WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 5);
		menuPosition[7].x = (float)(WINDOW_WIDTH / 2 + 1.2*WINDOW_WIDTH / 20);
		menuPosition[7].y = (float)(WINDOW_HEIGHT / 2 + WINDOW_HEIGHT / 5);
		//Загрузка текстур
		Arrows[0].loadFromFile("resource/images/menu/arrow-left.png");
		Arrows[1].loadFromFile("resource/images/menu/arrow-right.png");

		Textures[0].loadFromFile("resource/images/maps/texturemenu1.png");
		Textures[1].loadFromFile("resource/images/maps/texturemenu2.png");

		//Присвоение спрайтам текстур
		for (int i = 0; i < N + 2; i++) {
			if (i < 2) {
				menuElements[i].setTexture(Arrows[i]);
				menuElements[i].setScale(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width,
					WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height);
			}
			else {
				menuElements[i].setTexture(Textures[i - 2]);
				menuElements[i].setScale(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width,
					WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height);
			}
		}


		//Установление размера и шрифта надписям
		for (int i = 0; i < 2; i++) {
			menuButton[i].setFont(font);
			menuButton[i].setCharacterSize(WINDOW_WIDTH / 33);
		}

		for (int i = 0; i < 7; i++) {
			colorChoose[i].setFont(font);
			colorChoose[i].setCharacterSize(WINDOW_WIDTH / 45);
		}

		//Инициализация надписей
		menuButton[0].setString("Start Game");
		menuButton[1].setString("Back");

		colorChoose[0].setString("Red");
		colorChoose[0].setColor(red);
		colorChoose[1].setString("Blue");
		colorChoose[1].setColor(blue);
		colorChoose[2].setString("Green");
		colorChoose[2].setColor(green);
		colorChoose[3].setString("Orange");
		colorChoose[3].setColor(orange);
		colorChoose[4].setString("Yellow");
		colorChoose[4].setColor(yellow);
		colorChoose[5].setString("Black");
		colorChoose[5].setColor(black);
		colorChoose[6].setString("White");
		colorChoose[6].setColor(white);

		//Проверка наведения мыши
		for (int i = 0; i < 2; i++) {
			if (sf::IntRect(menuPosition[i].x, menuPosition[i].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))) {
				menuButton[i].setColor(sf::Color(255, 0, 0, 255));
				menuButton[i].setCharacterSize(WINDOW_WIDTH / 30);
			}
		}

		//Проверка нажатий на кнопки
		//Start
		if (sf::IntRect(menuPosition[0].x, menuPosition[0].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			eventGameSettingsRender = false;
			eventGameStart = true;
		}
		
		//Back
		if (sf::IntRect(menuPosition[1].x, menuPosition[1].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			eventMenuRender = true;
			eventGameSettingsRender = false;
		}
		//Верхняя левая стрелка
		if (sf::IntRect(menuPosition[2].x, menuPosition[2].y, WINDOW_WIDTH/ 19.2, WINDOW_HEIGHT/ 10.8).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			numOfTexture -= 1;
		}
		//Правая верхняя стрелка
		if (sf::IntRect(menuPosition[3].x, menuPosition[3].y, WINDOW_WIDTH / 19.2, WINDOW_HEIGHT / 10.8).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			numOfTexture += 1;
		}

		//Нижняя левая стрелка
		if (sf::IntRect(menuPosition[6].x, menuPosition[6].y, WINDOW_WIDTH / 19.2, WINDOW_HEIGHT / 10.8).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			 colorChooseNumber -= 1;
		}
		//Правая нижняя стрелка
		if (sf::IntRect(menuPosition[7].x, menuPosition[7].y, WINDOW_WIDTH / 19.2, WINDOW_HEIGHT / 10.8).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			colorChooseNumber += 1;
		}


		//Учет ротации и выход за границы
		if (numOfTexture > (N - 1)) {
			numOfTexture = 0;
		}
		if (numOfTexture < 0) {
			numOfTexture = N - 1;
		}

		if (colorChooseNumber > 6) {
			colorChooseNumber = 0;
		}
		if (colorChooseNumber < 0) {
			colorChooseNumber = 6;
		}

		//Рендер текста и стрелок
		for (int i = 0; i < 2; i++) {
				menuButton[i].setPosition(menuPosition[i]);
				window.draw(menuButton[i]);
				menuElements[i].setPosition(menuPosition[i + 2]);
				window.draw(menuElements[i]);
				menuElements[i].setPosition(menuPosition[i + 6]);
				window.draw(menuElements[i]);
		}
		//Рендер текстур
		for (int i = 0; i < N + 2; i++) {
			menuElements[i].setPosition(menuPosition[4]);
		}
		window.draw(menuElements[numOfTexture + 2]);
		//Рендер надписей с цветами
		for (int i = 0; i < 7; i++) {
			colorChoose[i].setPosition(menuPosition[5]);
		}
		window.draw(colorChoose[colorChooseNumber]);

	}
}

void gameStart(bool start) {
	if (start) {
		singleRender(eventSingleRender);
		groundPhysics();
		drawTerrarian();
	}
}

void drawTerrarian() {

	if (terrarianFlag) {
		//Вывод ландшафта(использован объект Image для ускорения)
		for (int i = 0; i < 2500; i++) {
			for (int j = 0; j < 1000; j++) {
				if (terrarian[i][j] == true) {
					//Свитч для различных типов ландшафта(при выборе в меню)
					switch (numOfTexture) {
					case 0: {
						terrarianImage.setPixel(i, j, sf::Color(118, 50, 19));
						break;
					}
					case 1: {
						terrarianImage.setPixel(i, j, white);
						break;
					}
					}
				}
				else
					//Если нет текстуры, то заполнить прозрачным пикселем
					terrarianImage.setPixel(i, j, sf::Color::Transparent);
			}
		}
		terrarianFlag = false;
	}

	//Заготовка для вывода
	sf::Texture terrarianTexture;
	sf::Sprite terrarianSprite;
	terrarianTexture.loadFromImage(terrarianImage);
	terrarianSprite.setTexture(terrarianTexture);
	terrarianSprite.setPosition(0, 0);
	//Изменение размера под разные разрешения
	terrarianSprite.setScale(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width,
		WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height);

	//Фон
	sf::Vertex rectangle[] =
	{
		sf::Vertex(sf::Vector2f(0,0), sf::Color(0, 71, 107)),
		sf::Vertex(sf::Vector2f(2500,0), sf::Color(0, 71, 107)),
		sf::Vertex(sf::Vector2f(2500,1000), black),
		sf::Vertex(sf::Vector2f(0,1000), black),
	};
	//Отрисовка
	window.draw(rectangle, 4, sf::Quads);

	//Рендер звездочек
	sf::Texture starTexture;
	starTexture.loadFromFile("resource/images/maps/star.png");
	sf::Sprite starSprite;
	starSprite.setTexture(starTexture);

	if (waterTime > 1000) {
		waterTime = 0;
	}

	//Рендер воды перед ландшафтом
	sf::Texture waterTexture;
	waterTexture.loadFromFile("resource/images/maps/water.png");
	sf::Sprite waterSprite;
	waterSprite.setTexture(waterTexture);

		for (int i = 0; i < 2500; i += 50) {
			waterSprite.setTextureRect(sf::IntRect(water*50, 0, 100, 80));
			waterSprite.setPosition((float)i, WINDOW_HEIGHT - WINDOW_HEIGHT / 6);
			water += 0.00001;
			if (water > 3) {
				water = 1;
			}

			window.draw(waterSprite);
		}

	for (int i = 0; i < 70; i++) {
		starSprite.setPosition((float)stars[0][i], (float)stars[1][i]);
		window.draw(starSprite);
	}
	//Отрисовка ландшафта
	window.draw(terrarianSprite);
		//Рендер воды после ландшафта
		for (int j = WINDOW_HEIGHT - (int)(WINDOW_HEIGHT / 7); j <= WINDOW_HEIGHT + 100; j += (int)(WINDOW_HEIGHT / 25)) {
			for (int i = 0; i < 2500; i += 50) {
				waterSprite.setTextureRect(sf::IntRect(water*50, 0, 100, 80));
				waterSprite.setPosition((float)i, j);
				water += 0.00001;
				if (water > 3) {
					water = 1;
				}

				window.draw(waterSprite);
			}
		}

	}


void singleRender(bool render) {
	if (render) {
		//Просчёт координат для звёздочек
		for (int j = 0; j < 70; j++) {
			stars[0][j] = randomNumber(1, 2500);
			stars[1][j] = randomNumber(1, WINDOW_HEIGHT/2);
		}
		generateTerrarian();
		terrarianImage.create(2500, 1000);

		wormTexture.loadFromFile("resource/images/worms/worms.png");
		wormSprite.setTexture(wormTexture);
		eventSingleRender = false;
	}
}

sf::Sprite resize(sf::Sprite sprite) {
	sprite.setScale(WINDOW_WIDTH / sprite.getLocalBounds().width,
		WINDOW_HEIGHT / sprite.getLocalBounds().height);
	return sprite;
}

void wormRender() {
	for (int i = 0; i < 6; i++) {
		if (i == currentWorm) {
			while (worm[i].isMoveLeft) {
				int key = 0;
				wormSprite.setTextureRect(sf::IntRect(key * 40, 0, 40, 40));
				wormSprite.setPosition(worm[i].position.x*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width),
					worm[i].position.y*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height));
				key++;
				if (key > 3) {
					key = 0;
				}
				window.draw(wormSprite);
			}
			while (worm[i].isMoveRight) {
				int key = 0;
				wormSprite.setTextureRect(sf::IntRect(key * 40, 40, 40, 40));
				key++;
				if (key > 3) {
					key = 0;
				}
			}

		}
	}
}