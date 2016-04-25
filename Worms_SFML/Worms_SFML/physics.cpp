#include "includes.hpp"

void insides() {
	/*
b2BodyDef myBodyDef;
myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
myBodyDef.position.Set(0, 20); //set the starting position
myBodyDef.angle = 0; //set the starting angle

b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);
*/sf::Image image;
	image.create(2500, 1000);
	for (int i = 0; i < 2500; i++){
		for (int j = 0; j < 1000; j++){
			{
				if ((terrarian[i][j] == 1) && 
					((terrarian[i][j + 1] == 0) ||
					(terrarian[i][j - 1] == 0) ||
					(terrarian[i + 1][j] == 0) ||
					((terrarian[i + 1][j-1] == 0)) || 
					(terrarian[i + 1][j + 1] == 0) || 
					(terrarian[i - 1][j] == 0) || 
					(terrarian[i - 1][j + 1] == 0) || 
					(terrarian[i - 1][j - 1] == 0)))
				{
					b2BodyDef myBodyDef;
					myBodyDef.position.Set(i, j); //set the starting position
					myBodyDef.angle = 0;

				/*	sf::Vertex rectangle[] =
					{
						sf::Vertex(sf::Vector2f(i - 100,j - 73), red),
						sf::Vertex(sf::Vector2f(i - 99,j - 73), red),
						sf::Vertex(sf::Vector2f(i - 99,j -72), red),
						sf::Vertex(sf::Vector2f(i - 100,j -72), red),
					};
					//Отрисовка
					window.draw(rectangle, 4, sf::Quads);*/

					image.setPixel(i, j, red);
					image.setPixel(i-1, j, red);
					image.setPixel(i, j-1, red);
					image.setPixel(i-1, j-1, red);
				}
				else
					image.setPixel(i, j, sf::Color::Transparent);
			}
		}
	}
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	//Изменение размера под разные разрешения
	sprite.setScale(WINDOW_WIDTH / backgroundSprite.getLocalBounds().width,
		WINDOW_HEIGHT / backgroundSprite.getLocalBounds().height);
	window.draw(sprite);
}