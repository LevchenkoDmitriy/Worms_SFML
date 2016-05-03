#include <includes.hpp>

wormFields *worm = new wormFields[6];
int currentWorm = 0;
bool exitFor = false;

void generateWorms() {
	for (int k = 0; k < 6; k++) {
		worm[k].isDead = false;
		worm[k].health = 100;
		worm[k].team = colorChooseNumber;
		worm[k].numberOfWorm = k;

		worm[k].isMoveLeft = 0;
		worm[k].isMoveRight = 0;
		worm[k].isFalling = 0;
		worm[k].isJump = 0;

		int x = 0;
		for (int i = 0; i < 2500; i++) {
			for (int j = 0; j < 1000; j++) {
				if ((terrarian[i][j] == true) &&
					((terrarian[i - 1][j - 1] == 0) || (terrarian[i][j - 1]) || (terrarian[i + 1][j - 1] == 0))&&
					(j < 500)) {
					int x = randomNumber(1, 10);
					if (x == 5) {
						worm[k].position.x = i*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width);
						worm[k].position.y = j*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height)-100;
						exitFor = true;
						break;
					}
				}
			}
			if (exitFor) {
				exitFor = false;
				break;
			}
		}

	}

}

