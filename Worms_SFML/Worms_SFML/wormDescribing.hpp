#pragma once
#ifndef WORMHANDLING_H
#define WORMHANDLING_H
#include "includes.hpp"


class Worm {
public:
	float x, y, w, h, dx, dy, speed; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir; //����������� (direction) �������� ������
	sf::String File; //���� � �����������
	sf::Image image;
	sf::Texture wormTexture;//���� ��������
	sf::Sprite wormSprite;//���� ������

	Worm(sf::String F, float X, float Y, float W, float H) { //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
		dx = 0; dy = 0; speed = 0; dir = 0;
		File = F;//��� �����+����������
		w = W; h = H;//������ � ������
		image.loadFromFile("images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");
		wormTexture.loadFromFile("resource/images/worms/worms.png");
		wormSprite.setTexture(wormTexture);//�������� ������ ���������
		x = X; y = Y;//���������� ��������� �������
		wormSprite.setTextureRect(sf::IntRect(0, 0, w, h)); //������ ������� ���� ������������� ��� ������ ������ ����, � �� ���� ����� �����. IntRect - ���������� �����
	}
	void update(float time) //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
	{
		switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
		{
		case 0: dx = speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
		case 1: dx = -speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
		case 2: dx = 0; dy = speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
		case 3: dx = 0; dy = -speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
		}

		x += dx*time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
		y += dy*time;//���������� �� ������

		speed = 0;//�������� ��������, ����� �������� �����������.
		wormSprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	}

	void wormGeneratePhysics() {
		for (int i = 0; i < 6; i++) {
			b2BodyDef bodyDef;
			bodyDef.type = b2_dynamicBody;
			bodyDef.position.Set(worm[i].position.x / SCALE, worm[i].position.y / SCALE);
			bodyDef.fixedRotation = true;

			body[i] = world.CreateBody(&bodyDef);			b2PolygonShape dynamicBox;
			dynamicBox.SetAsBox(0.4, 0.45);			b2FixtureDef fixtureDef;
			fixtureDef.shape = &dynamicBox;
			fixtureDef.density = 100.0f;
			fixtureDef.friction = 0.03f;			body[i]->CreateFixture(&fixtureDef);

			//��������� ������������� ��� ����������� �� ����� �� ��� ���
			dynamicBox.SetAsBox(0.3, 0.3, b2Vec2(0, -0.45), 0);
			fixtureDef.isSensor = true;
			b2Fixture* footSensorFixture = body[i]->CreateFixture(&fixtureDef);
			footSensorFixture->SetUserData((void*)i);


		}


};
};

#endif