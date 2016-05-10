#include <includes.hpp>

wormFields *worm = new wormFields[8];
int currentWorm = 0;


int leftX = 0;
int rightX = 0;
double moveTimerLeft = 0;
double moveTimerRight = 0;
bool win = false;
bool finalTitle = false;

void deathChecking() {
	for (int i = 0; i < 8; i++) {
		b2Vec2 position = body[i]->GetPosition();
		float angle = body[i]->GetAngle();
		if (position.y*SCALE > (WINDOW_HEIGHT-80)*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height)) {
			worm[i].isDead = true;
		}
		if (worm[i].health <= 0) {
			worm[i].isDead = true;
		}
	}
}

void GetNull() {
	 eventMenuRender = true;
	 eventGameSettingsRender = false;
	 eventGameStart = false;
	 eventSingleRender = true;
	 terrarianFlag = true;
	 pause = false;
	 numOfTexture = 0;
	 colorChooseNumber = 0;
	 terrarian[2500][1000] = { 0 };
	 stars[2][400] = { 0 };
	 water = 1;
	 currentWorm = 0;
	 leftX = 0;
	 rightX = 0;
	 moveTimerLeft = 0;
	 moveTimerRight = 0;
	 win = false;
	 finalTitle = false;
	 bullet = false;
	 contact = false;
	 groundSavePhysics[2500][1000] = { false };
	 quit = false; 
	 rocket = NULL;
}

void Final(int winner) {
		window.clear();
		sf::Font font;
		font.loadFromFile("resource/fonts/AdLib.ttf");
		sf::Text menuButton[3];
		sf::Vector2f menuPosition[3];
		//ћинутка индусского кода :\, черт знает как нормально инициализировать
		menuPosition[0].x = (float)(WINDOW_WIDTH / 2 - WINDOW_WIDTH / 20);
		menuPosition[0].y = (float)(WINDOW_HEIGHT / 3 + WINDOW_HEIGHT / 15);
		menuPosition[1].x = (float)(WINDOW_WIDTH / 2 - WINDOW_WIDTH / 20);
		menuPosition[1].y = (float)(WINDOW_HEIGHT / 3 + 3 * WINDOW_HEIGHT / 15);
		menuPosition[2].x = (float)(WINDOW_WIDTH / 2 - WINDOW_WIDTH / 20);
		menuPosition[2].y = (float)(WINDOW_HEIGHT / 3 - WINDOW_HEIGHT / 15);

		for (int i = 0; i < 3; i++) {
			menuButton[i].setFont(font);
			menuButton[i].setCharacterSize(WINDOW_WIDTH / 33);
		}

		menuButton[0].setString("Go to menu");
		menuButton[1].setString("Exit");
		if (winner == 0) {
			menuButton[2].setString("Draw!");
		}else
			if (winner == 1) {
				menuButton[2].setString("Team 1 won!");
			}else
				if (winner == 2) {
					menuButton[2].setString("Team 2 won!");
				}

		//ѕроверка наведени€ мыши
		for (int i = 0; i < 2; i++) {
			if (sf::IntRect(menuPosition[i].x, menuPosition[i].y, (int)(WINDOW_WIDTH / 33 * 4), (int)(WINDOW_WIDTH / 25)).contains(sf::Mouse::getPosition(window))) {
				menuButton[i].setColor(sf::Color(255, 0, 0, 255));
				menuButton[i].setCharacterSize(WINDOW_WIDTH / 30);
			}
		}

		//ѕроверка нажатий на кнопки
		//Go to menu
		if (sf::IntRect(menuPosition[0].x, menuPosition[0].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {

			GetNull();

		}

		//Exit
		if (sf::IntRect(menuPosition[1].x, menuPosition[1].y, WINDOW_WIDTH / 33 * 4, WINDOW_WIDTH / 25).contains(sf::Mouse::getPosition(window))
			&& (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
			quit = true;
		}

		for (int i = 0; i < 3; i++) {
			menuButton[i].setPosition(menuPosition[i]);
			window.draw(menuButton[i]);
		}
}

void WinnerChecking() {
	if (eventGameStart) {
		int firstTeam = 0;
		int secondTeam = 0;
		//-1 - нет победы, 0 - ничь€, 1 - победа 1 команды, 2 - победа 2 команды
		int winner = -1;

		for (int i = 0; i < 4; i++) {
			if (worm[i].isDead) {
				firstTeam++;
			}
			if (worm[i + 4].isDead) {
				secondTeam++;
			}
		}

		if (firstTeam == 4) {
			winner = 2;
			Final(winner);
			win = true;
		}
		else
			if (secondTeam == 4) {
				winner = 1;
				Final(winner);
				win = true;
			}
			else
				if (firstTeam == secondTeam == 4) {
					winner = 0;
					Final(winner);
					win = true;
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

void wormRotation(bool flag) {
	if (worm[currentWorm].isDead) {
		if (currentWorm == 7) {
			currentWorm = 0;
		}
		else
			currentWorm++;
	}if (flag) {
		if (currentWorm == 7) {
			currentWorm = 0;
		}
		else
			currentWorm++;
	}
}