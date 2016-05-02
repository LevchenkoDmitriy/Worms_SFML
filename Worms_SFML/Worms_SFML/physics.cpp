#include "includes.hpp"

int save[2500][1000] = { 0 };
const int SCALE = 30.0f;
const int RAD = 57.2958;

void insides() {
	
	for (int i = 0; i < 2500; i++) {
		for (int j = 0; j < 1000; j++) {
			{
				if ((terrarian[i][j] == 1) && (save[i][j] != 1) &&
					((terrarian[i][j + 1] == 0) ||
					(terrarian[i][j - 1] == 0) ||
						(terrarian[i + 1][j] == 0) ||
						((terrarian[i + 1][j - 1] == 0)) ||
						(terrarian[i + 1][j + 1] == 0) ||
						(terrarian[i - 1][j] == 0) ||
						(terrarian[i - 1][j + 1] == 0) ||
						(terrarian[i - 1][j - 1] == 0)))
				{
					save[i][j] = 1;
					b2BodyDef myBodyDef;
					myBodyDef.position.Set(i, j); //set the starting position
					myBodyDef.angle = 0;
				}
			}
		}
	}
}