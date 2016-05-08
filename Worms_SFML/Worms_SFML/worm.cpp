#include <includes.hpp>

wormFields *worm = new wormFields[6];
int currentWorm = 0;

int leftX = 0;
int rightX = 0;
double moveTimerLeft = 0;
double moveTimerRight = 0;

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
		for (b2ContactEdge* edge = body[currentWorm]->GetContactList(); edge; edge = edge->next) {
			if (edge->contact->IsTouching()) {
				worm[currentWorm].onGround = true;
			}
	}

}

void setGround() {
	for (int i = 0; i < 6; i++) {
		worm[i].onGround = false;
	}
}