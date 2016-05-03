#include <includes.hpp>

sf::View camera(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)); //объ€вление вида

void getPlayerCoordinateForView() {
	b2Vec2 position = body[currentWorm]->GetPosition();
	if (position.x*SCALE < WINDOW_WIDTH / 2) {
		camera.setCenter(WINDOW_WIDTH/2, position.y*SCALE);
		if (position.y*SCALE > WINDOW_HEIGHT/2)
		{
			camera.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT/2 );
		}
		if (position.y*SCALE > WINDOW_HEIGHT) {
			camera.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT/2);
		}
	}else
		if (position.x*SCALE > 2500* (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width)) {
			camera.setCenter(2500  - WINDOW_WIDTH / 2, position.y*SCALE);
		}

	else
	camera.setCenter(position.x* SCALE, position.y*SCALE);
};
