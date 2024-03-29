#include "includes.hpp"

bool eventMenuRender = true;
bool eventGameSettingsRender = false;
bool eventGameStart = false;
bool eventSingleRender = true;
bool terrarianFlag = true;
bool pause = false;
int numOfTexture = 0;
int colorChooseNumber = 0;
float key = 0;

bool terrarian[2500][1000] = { 0 };
int stars[2][400] = { 0 };
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
			if (sf::IntRect(menuPosition[i].x, menuPosition[i].y, (int)(WINDOW_WIDTH / 33 * 4), (int)(WINDOW_WIDTH / 25)).contains(sf::Mouse::getPosition(window))) {
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
		for (int i = 0; i < 8; i++) {
			colorChoose[i].setPosition(menuPosition[5]);
		}
		window.draw(colorChoose[colorChooseNumber]);

	}
}

void gameStart(bool start) {
	if (start) {
		float32 timeStep = 1.0f / 60.0f;		int32 velocityIterations = 8;
		int32 positionIterations = 3;

		singleRender(eventSingleRender);
		groundPhysics();

		deathChecking();
		wormRotation(false);

		getPlayerCoordinateForView();

		world.Step(timeStep, velocityIterations, positionIterations);
		drawTerrarian();
		wormRenderMoving();
		drawWormName();

		checkBullet();
		renderWeapon();
		renderBullet();
		drawBoom();

		setGround();

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
		sf::Vertex(sf::Vector2f(-1000,-1000), sf::Color(0, 71, 107)),
		sf::Vertex(sf::Vector2f(3500,-1000), sf::Color(0, 71, 107)),
		sf::Vertex(sf::Vector2f(3500,1000), black),
		sf::Vertex(sf::Vector2f(-1000,1000), black),
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

		for (int i = 0; i < 3500; i += 50) {
			waterSprite.setTextureRect(sf::IntRect((float)(water*50), 0, 100, 80));
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
			for (int i = 0; i < 3500; i += 50) {
				waterSprite.setTextureRect(sf::IntRect((float)(water*50), 0, 100, 80));
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
		for (int j = 0; j < 400; j++) {
			stars[0][j] = randomNumber(-1000, 3500);
			stars[1][j] = randomNumber(-1000, 500);
		}
		generateTerrarian();
		terrarianImage.create(2500, 1000);

		win = false;

		generateWorms();
		wormGeneratePhysics();
		eventSingleRender = false;
	}
}

void wormRenderMoving() {
	wormRender wormMovingState;

	wormMovingState.wormRenderStatic();
	if (worm[currentWorm].onGround) {
		wormMovingState.wormStaticCurrentRender();
	}

	if (worm[currentWorm].isMoveLeft) {
		worm[currentWorm].view = false;
		wormMovingState.wormMovingLeftRender();
		worm[currentWorm].isMoveLeft = false;
	}
	else

		if (worm[currentWorm].isMoveRight) {
			worm[currentWorm].view = true;
			wormMovingState.wormMovingRightRender();
			worm[currentWorm].isMoveRight = false;
		}
	else
		if (!worm[currentWorm].onGround) {
			wormMovingState.wormJumpRender();
			worm[currentWorm].isJump = false;
		}
}

void drawWormName() {
	//Загрузка шрифтов
	sf::Font font;
	font.loadFromFile("resource/fonts/AdLib.ttf");

	sf::Text wormName[8];
	sf::Text wormHP[8];

	for (int i = 0; i < 8; i++) {
		wormName[i].setFont(font);
		wormName[i].setCharacterSize(WINDOW_WIDTH / 110);

		wormHP[i].setFont(font);
		wormHP[i].setCharacterSize(WINDOW_WIDTH / 110);

		std::string name = "worm ";
		std::string HP;

		HP += toString(worm[i].health);
		HP += "%";
		if (i < 4) {
		name += 49 + i;
		}else 
			name += 45 + i;

		wormHP[i].setString(HP);
		wormName[i].setString(name);
		if (i < 4) {
			switch (colorChooseNumber) {
			case 0:
				wormName[i].setColor(red);
				wormHP[i].setColor(red);
				break;
			case 1:
				wormName[i].setColor(blue);
				wormHP[i].setColor(blue);
				break;
			case 2:
				wormName[i].setColor(green);
				wormHP[i].setColor(green);
				break;
			case 3:
				wormName[i].setColor(orange);
				wormHP[i].setColor(orange);
				break;
			case 4:
				wormName[i].setColor(yellow);
				wormHP[i].setColor(yellow);
				break;
			case 5:
				wormName[i].setColor(black);
				wormHP[i].setColor(black);
				break;
			case 6:
				wormName[i].setColor(white);
				wormHP[i].setColor(white);
				break;
			}
		}
		else
		{
			wormName[i].setColor(white);
			wormHP[i].setColor(white);
		}
		b2Vec2 position = body[i]->GetPosition();

		wormName[i].setPosition(position.x*SCALE - SCALE, position.y*SCALE-2.1*SCALE);
		wormHP[i].setPosition(position.x*SCALE - SCALE, position.y*SCALE - 1.6*SCALE);

		window.draw(wormName[i]);
		if (!worm[i].isDead) {
			window.draw(wormHP[i]);
		}
	}
}

void menuPause(bool flag) {
	if (flag) {
	sf::Font font;
font.loadFromFile("resource/fonts/AdLib.ttf");
	sf::Text menuButton[2];
 sf::Vector2f menuPosition[2];
 //Минутка индусского кода :\, черт знает как нормально инициализировать
 menuPosition[0].x = (float)(WINDOW_WIDTH / 2 - WINDOW_WIDTH / 20);
 menuPosition[0].y = (float)(WINDOW_HEIGHT / 3 + WINDOW_HEIGHT / 15);
 menuPosition[1].x = (float)(WINDOW_WIDTH / 2 - 1.3*WINDOW_WIDTH / 20);
 menuPosition[1].y = (float)(WINDOW_HEIGHT / 3 + 3 * WINDOW_HEIGHT / 15);

 for (int i = 0; i < 2; i++) {
	 menuButton[i].setFont(font);
	 menuButton[i].setCharacterSize(WINDOW_WIDTH / 33);
 }

 menuButton[0].setString("Go to menu");
 menuButton[1].setString("Continue game");

 //Проверка наведения мыши
 for (int i = 0; i < 2; i++) {
	 if (sf::IntRect(menuPosition[i].x, menuPosition[i].y, (int)(WINDOW_WIDTH / 33 * 4), (int)(WINDOW_WIDTH / 25)).contains(sf::Mouse::getPosition(window))) {
		 menuButton[i].setColor(sf::Color(255, 0, 0, 255));
		 menuButton[i].setCharacterSize(WINDOW_WIDTH / 30);
	 }
 }

 //Проверка нажатий на кнопки
 //Go to menu
 if (sf::IntRect(menuPosition[0].x, menuPosition[0].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
	 && (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
	 pause = false;
	 GetNull();
	 eventGameStart = false;
	 eventMenuRender = true;

 }

 //Continue game
 if (sf::IntRect(menuPosition[1].x, menuPosition[1].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
	 && (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
	 pause = false;

 }

 for (int i = 0; i < 2; i++) {
	 menuButton[i].setPosition(menuPosition[i]);
	 window.draw(menuButton[i]);
		}
	}

}
