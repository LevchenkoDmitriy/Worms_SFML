#include <includes.hpp>

wormFields *worm;
int currentWorm = 0;

void generateWorms() {
	wormFields *worm = (wormFields*)malloc(6*sizeof(wormFields));
	for (int k = 0; k < 6; k++) {
		worm[k].isDead = false;
		worm[k].health = 100;
		worm[k].team = colorChooseNumber;
		int x = 0;
		for (int i = 0; i < 2500; i++) {
			for (int j = 0; j < 1000; j++) {
				if ((terrarian[i][j] == true) &&
					((terrarian[i - 1][j - 1] == 0) || (terrarian[i][j - 1]) || (terrarian[i + 1][j - 1] == 0))) {
					x = randomNumber(1, 20);
					if (x == 8) {
						worm[k].position.x = i*(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width);
						worm[k].position.y = j*(WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height);
						break;
					}
				}
			}
			if (x == 8) {
				break;
			}
		}

	}

}

