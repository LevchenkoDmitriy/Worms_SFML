#include <includes.hpp>

wormFields *worm = new wormFields[8];
int currentWorm = 0;


int leftX = 0;
int rightX = 0;
double moveTimerLeft = 0;
double moveTimerRight = 0;
bool finalTitle = false;

void deathChecking() {
	for (int i = 0; i < 8; i++) {
		b2Vec2 position = body[i]->GetPosition();
		float angle = body[i]->GetAngle();
		if (position.y*SCALE > (WINDOW_HEIGHT-80)*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height)) {
			worm[i].isDead = true;
		}
		if (position.x*SCALE > WINDOW_WIDTH*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().height)) {
			worm[i].isDead = true;
		}
		if (position.y*SCALE < 0) {
			worm[i].isDead = true;
		}
		if (worm[i].health <= 0) {
			worm[i].isDead = true;
		}
	}
}

void Final() {
	if (finalTitle) {
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
		menuButton[1].setString("Exit");

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
			window.clear();
			eventMenuRender = true;

		}

		//Exit
		if (sf::IntRect(menuPosition[1].x, menuPosition[1].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			quit = true;
		}

		for (int i = 0; i < 2; i++) {
			menuButton[i].setPosition(menuPosition[i]);
			window.draw(menuButton[i]);
		}
	}
}

void WinnerChecking() {
	int first = 0;
	int second = 0;
	sf::Font font;
	font.loadFromFile("resource/fonts/AdLib.ttf");
	sf::Text menuButton[1];
	for (int i = 0; i < 4; i++) {
		if (worm[i].isDead == true) {
			first = 0;
		}
		else first = 1;
	}

	for (int i = 4; i < 8; i++) {
		if (worm[i].isDead == true) {
			second = 0;
		}
		else second = 1;
	}

	if (first == 0) {
		if (second == 0) {
			window.clear();
			menuButton[1].setFont(font);
			menuButton[1].setCharacterSize(WINDOW_WIDTH / 33);
			menuButton[1].setString("Winner: Nobody");
			finalTitle = true;
			Final();
		}
		else {
			window.clear();
			menuButton[1].setFont(font);
			menuButton[1].setCharacterSize(WINDOW_WIDTH / 33);
			menuButton[1].setString("Winner: Second team");
			finalTitle = true;
			Final();
		}
	}
		
	if (second == 0) {
		if (first == 0) {
			window.clear();
			menuButton[1].setFont(font);
			menuButton[1].setCharacterSize(WINDOW_WIDTH / 33);
			menuButton[1].setString("Winner: Nobody");
			finalTitle = true;
			Final();
		}

		else {
			window.clear();
			menuButton[1].setFont(font);
			menuButton[1].setCharacterSize(WINDOW_WIDTH / 33);
			menuButton[1].setString("Winner: First team");
			finalTitle = true;
			Final();
		}
	}

}

void generateWorms() {
	for (int k = 0; k < 8; k++) {
		worm[k].isDead = false;
		worm[k].health = 100;
		worm[k].team = colorChooseNumber;
		worm[k].numberOfWorm = k;

		worm[k].isMoveLeft = false;
		worm[k].isMoveRight = false;
		worm[k].onGround = false;
		worm[k].isJump = false;
		worm[k].view = false;

		bool generate = true;
		while(generate){
			int i = randomNumber(1, 2500);
			int j = randomNumber(1, 1000);
			if ((terrarian[i][j] == true) &&
				((terrarian[i - 1][j - 1] == 0) || (terrarian[i][j - 1]) || (terrarian[i + 1][j - 1] == 0))){
					worm[k].position.x = i*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width);
					worm[k].position.y = 50;
					generate = false;
			}

		}
	}
}

void checkGround() {
	for (int i = 0; i < 8; i++) {
		for (b2ContactEdge* edge = body[i]->GetContactList(); edge; edge = edge->next) {
			if (edge->contact->IsTouching()) {
				worm[i].onGround = true;
			}
		}
	}
}

void setGround() {
	for (int i = 0; i < 8; i++) {
		worm[i].onGround = false;
	}
}

void wormRotation() {
	if (worm[currentWorm].isDead) {
		if (currentWorm == 7) {
			currentWorm = 0;
		}
		else
			currentWorm++;
	}
}