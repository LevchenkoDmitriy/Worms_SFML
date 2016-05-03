#include <includes.hpp>

wormFields *worm = new wormFields[6];
bool exitFor = false;

void deathChecking() {
	for (int i = 0; i < 6; i++) {
		b2Vec2 position = body[i]->GetPosition();
		float angle = body[i]->GetAngle();
		if ((position.x > 2480) ||
			(position.x < -980) ||
			(position.y < -970) ||
			(position.y > 800)) {
			worm[i].isDead = true;
		}
	}
}

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
		worm[k].isJumpLeft = 0;
		worm[k].isJumpRight = 0;

		int x = 0;
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

void filterWormMoving() {

}