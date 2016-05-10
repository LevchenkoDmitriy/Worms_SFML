#include <includes.hpp>

sf::View camera(sf::FloatRect(0, 0, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT)); //���������� ����

void getPlayerCoordinateForView() {
	if (!pause && !win) {
		b2Vec2 position = body[currentWorm]->GetPosition();
	
		//����� ����� ������, ��� ��������!

		//�������������� �������: ���� �������������� ����� �� ����� �� ������
		if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) ||
			(position.y*SCALE > WINDOW_HEIGHT / 2) ||
			(position.x*SCALE < WINDOW_WIDTH / 2) ||
			(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
			//������ �����
			if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
				!(position.x*SCALE < WINDOW_WIDTH / 2) &&
				!(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
				camera.setCenter((float)(position.x* SCALE), (float)(-1000 + WINDOW_HEIGHT / 2));
			}
			//����� � �����
			else if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
				(position.x*SCALE < WINDOW_WIDTH / 2)) {
				camera.setCenter((float)(WINDOW_WIDTH / 2), (float)(-1000 + WINDOW_HEIGHT / 2));
			}
			//����� � ������
			else if ((position.y*SCALE < -1000 + WINDOW_HEIGHT / 2) &&
				(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
				camera.setCenter((float)(2500 - WINDOW_WIDTH / 2), (float)(-1000 + WINDOW_HEIGHT / 2));
			}
			//������ ����
			else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
				!(position.x*SCALE < WINDOW_WIDTH / 2) &&
				!(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
				camera.setCenter((float)(position.x*SCALE), (float)(WINDOW_HEIGHT / 2));

			}
			//���� � �����
			else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
				(position.x*SCALE < WINDOW_WIDTH / 2)) {
				camera.setCenter((float)(WINDOW_WIDTH / 2), (float)(WINDOW_HEIGHT / 2));
			}
			//���� � ������
			else if ((position.y*SCALE > WINDOW_HEIGHT / 2) &&
				(position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width))) {
				camera.setCenter((float)(2500 - WINDOW_WIDTH / 2), (float)(WINDOW_HEIGHT / 2));
			}
			//������ �����
			else if ((position.x*SCALE < WINDOW_WIDTH / 2) &&
				!(position.y*SCALE > WINDOW_HEIGHT / 2) &&
				!(position.y*SCALE < -1000 + WINDOW_HEIGHT / 2)) {
				camera.setCenter((float)(WINDOW_WIDTH / 2), (float)(position.y*SCALE));
			}
			//������ ������
			else if ((position.x*SCALE > 2500 * (WINDOW_WIDTH / backgroundSprite.getLocalBounds().width)) &&
				!(position.y*SCALE > WINDOW_HEIGHT / 2) &&
				!(position.y*SCALE < -1000 + WINDOW_HEIGHT / 2)) {
				camera.setCenter((float)(2500 - WINDOW_WIDTH / 2), (float)(position.y*SCALE));
			}
		}
		//���� �� ����
		else
			camera.setCenter((float)(position.x* SCALE), (float)(position.y*SCALE));
	}
	else
		camera.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
};
