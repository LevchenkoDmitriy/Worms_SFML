#include "includes.hpp"

void generateTerrarian() {
	sf::Image terrarianTexture;
	terrarianTexture.loadFromFile("map1.png");
	//Получаем цвет пикселя, если черный, то заносим 0, иначе 1
	for (int i = 0; i < 2500; i++) {
		for (int j = 0; j < 1000; j++) {
			if (terrarianTexture.getPixel(i, j) == black) {
				terrarian[i][j] = false;
			}
			else
				terrarian[i][j] = true;
		}
	}
}