#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	sf::IntRect currentFrame;

	//Core
	void initTexture();
	void initSprite();

	float movementSpeed;
	
	sf::RectangleShape body;

public:
	Player();
	virtual ~Player();

	//modifier
	void setPosition(const float x, const float y);
	void move(const float dirX, const float dirY);

	//functions
	void update();
	void render(sf::RenderTarget& target);

	void updateMovement();
};

