#include <includes.hpp>

sf::View camera(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)); //объявление вида

void getPlayerCoordinateForView() {
	b2Vec2 position = body[currentWorm]->GetPosition();
	//Слава богам Олимпа, оно работает!

	//Первоначальное условие: если осуществляется выход за любую из границ
	if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) ||
		(position.y*SCALE > WINDOW_HEIGHT / 2) ||
		(position.x*SCALE < WINDOW_WIDTH / 2) ||
		(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))){
		//Только вверх
		if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
			!(position.x*SCALE < WINDOW_WIDTH / 2) &&
			!(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(position.x* SCALE, -1000 + WINDOW_HEIGHT / 2);
		}
		//Вверх и влево
		else if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
			(position.x*SCALE < WINDOW_WIDTH / 2)) {
			camera.setCenter(WINDOW_WIDTH / 2, -1000 + WINDOW_HEIGHT / 2);
		}
		//Вверх и вправо
		else if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
			(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(2500 - WINDOW_WIDTH / 2, -1000 + WINDOW_HEIGHT / 2);
		}
		//Только вниз
		else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
			!(position.x*SCALE < WINDOW_WIDTH / 2) &&
			!(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(position.x*SCALE, WINDOW_HEIGHT / 2);

		}
		//Вниз и влево
		else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
			(position.x*SCALE < WINDOW_WIDTH / 2)) {
			camera.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		}
		//Вниз и вправо
		else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
			(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(2500 - WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		}
		//Только влево
		else if ((position.x*SCALE < WINDOW_WIDTH / 2) &&
			!(position.y*SCALE > WINDOW_HEIGHT / 2) &&
			!(position.y*SCALE < -1000 + WINDOW_HEIGHT / 2)) {
			camera.setCenter(WINDOW_WIDTH / 2, position.y*SCALE);
		}
		//Только вправо
		else if ((position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width)) &&
			!(position.y*SCALE > WINDOW_HEIGHT / 2) &&
			!(position.y*SCALE < -1000 + WINDOW_HEIGHT / 2)) {
			camera.setCenter(2500 - WINDOW_WIDTH / 2, position.y*SCALE);
		}
}
	//Если всё норм
	else
	camera.setCenter(position.x* SCALE, position.y*SCALE);
};
