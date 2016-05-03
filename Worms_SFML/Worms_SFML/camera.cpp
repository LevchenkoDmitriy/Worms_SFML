#include <includes.hpp>

sf::View camera(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)); //���������� ����

void getPlayerCoordinateForView() {
	b2Vec2 position = body[currentWorm]->GetPosition();
	//����� ����� ������, ��� ��������!

	//�������������� �������: ���� �������������� ����� �� ����� �� ������
	if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) ||
		(position.y*SCALE > WINDOW_HEIGHT / 2) ||
		(position.x*SCALE < WINDOW_WIDTH / 2) ||
		(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))){
		//������ �����
		if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
			!(position.x*SCALE < WINDOW_WIDTH / 2) &&
			!(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(position.x* SCALE, -1000 + WINDOW_HEIGHT / 2);
		}
		//����� � �����
		else if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
			(position.x*SCALE < WINDOW_WIDTH / 2)) {
			camera.setCenter(WINDOW_WIDTH / 2, -1000 + WINDOW_HEIGHT / 2);
		}
		//����� � ������
		else if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
			(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(2500 - WINDOW_WIDTH / 2, -1000 + WINDOW_HEIGHT / 2);
		}
		//������ ����
		else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
			!(position.x*SCALE < WINDOW_WIDTH / 2) &&
			!(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(position.x*SCALE, WINDOW_HEIGHT / 2);

		}
		//���� � �����
		else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
			(position.x*SCALE < WINDOW_WIDTH / 2)) {
			camera.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		}
		//���� � ������
		else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
			(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			camera.setCenter(2500 - WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		}
		//������ �����
		else if ((position.x*SCALE < WINDOW_WIDTH / 2) &&
			!(position.y*SCALE > WINDOW_HEIGHT / 2) &&
			!(position.y*SCALE < -1000 + WINDOW_HEIGHT / 2)) {
			camera.setCenter(WINDOW_WIDTH / 2, position.y*SCALE);
		}
		//������ ������
		else if ((position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width)) &&
			!(position.y*SCALE > WINDOW_HEIGHT / 2) &&
			!(position.y*SCALE < -1000 + WINDOW_HEIGHT / 2)) {
			camera.setCenter(2500 - WINDOW_WIDTH / 2, position.y*SCALE);
		}
}
	//���� �� ����
	else
	camera.setCenter(position.x* SCALE, position.y*SCALE);
};
