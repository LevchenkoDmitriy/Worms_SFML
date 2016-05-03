#include "includes.hpp"

void generateTerrarian() {
	sf::Image terrarianTexture;
	terrarianTexture.loadFromFile("resource/images/heightmap/map2.png");
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

int randomNumber(int start, int end) {
	//Получение времени с момента запуска в микросекундах
	sf::Time timeElapsed = elapsedTime.getElapsedTime();
	sf::Int64 usec = timeElapsed.asMicroseconds();
	srand(usec);
	printf("%d\n", (int)(start + rand() % (end - start)));
	return (int)(start + rand() % (end - start));
}

