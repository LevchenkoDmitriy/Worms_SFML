#include <includes.hpp>

sf::View camera(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)); //объ€вление вида
void getplayercoordinateforview(float x, float y) {
	camera.setCenter(x+500, y);
};
