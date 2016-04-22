#include "includes.hpp"

bool eventMenuRender = true;
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

void initLoadingImages() {

}
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
		for(int i = 0; i < 4; i++){
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
		if (sf::IntRect(menuPosition[3].x, menuPosition[3].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&&(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
				quit = true;
			}

	}
}
