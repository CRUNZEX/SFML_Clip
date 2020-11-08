#include "Player.h"

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/Player.png"))
		printf("ERROR::Texture.Player >> Not Load");
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.f, 1.f);

	this->currentFrame = sf::IntRect(0, 0, 100, 100);

	this->sprite.setPosition(300, 300);

	this->sprite.setTextureRect(this->currentFrame);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();

	this->movementSpeed = 5.f;
}

Player::~Player()
{
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
	this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(0.f, 1.f);
	}
}
