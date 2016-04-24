#include "includes.hpp"

bool eventMenuRender = true;
bool eventGameSettingsRender = false;
int numOfTexture = 0;
int colorChooseNumber = 0;

sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

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
		font.loadFromFile("AdLib.ttf");

		//Фоновая картинка меню
		backgroundTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
		backgroundTexture.loadFromFile("backgroundMenu.png");

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

		for (int i = 0; i < 4; i++) {
			menuButton[i].setPosition(menuPosition[i]);
			window.draw(menuButton[i]);
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

	}
}

void gameSettings(bool render) {
	if (render) {
		//Количество текстур для карт
		const int N = 2;

		//Загрузка шрифтов
		sf::Font font;
		font.loadFromFile("AdLib.ttf");

		//Фоновая картинка меню
		backgroundTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
		backgroundTexture.loadFromFile("backgroundMenu.png");

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
		Arrows[0].loadFromFile("arrow-left.png");
		Arrows[1].loadFromFile("arrow-right.png");
		Textures[0].loadFromFile("texturemenu1.png");
		Textures[1].loadFromFile("texturemenu2.png");

		//Присвоение спрайтам текстур
		for (int i = 0; i < N + 2; i++) {
			if (i < 2) {
				menuElements[i].setTexture(Arrows[i]);
			}
			else
				menuElements[i].setTexture(Textures[i-2]);
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
			//start game
		}
		
		//Back
		if (sf::IntRect(menuPosition[1].x, menuPosition[1].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			eventMenuRender = true;
			eventGameSettingsRender = false;
		}
		//Верхняя левая стрелка
		if (sf::IntRect(menuPosition[2].x, menuPosition[2].y, 100, 100).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			numOfTexture -= 1;
		}
		//Правая верхняя стрелка
		if (sf::IntRect(menuPosition[3].x, menuPosition[3].y, 100, 100).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			numOfTexture += 1;
		}

		//Нижняя левая стрелка
		if (sf::IntRect(menuPosition[6].x, menuPosition[6].y, 100, 100).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			 colorChooseNumber -= 1;
		}
		//Правая нижняя стрелка
		if (sf::IntRect(menuPosition[7].x, menuPosition[7].y, 100, 100).contains(sf::Mouse::getPosition(window))
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
