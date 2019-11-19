#include "Player.h"
#include <iostream>
Player::Player(){
	this->Health = 0;
	this->Speed = 0.1f;
	this->tx.loadFromFile("Assets/Player.png");
	this->sprite.setTexture(tx);
	this->sprite.setOrigin(tx.getSize().x / 2, 0.f);
	this->timer.restart();
	this->frate = 0.2f;
}
sf::Vector2f Player::getDir() {
	sf::Vector2f dir = sf::Vector2f(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		dir.x -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		dir.x += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		dir.y -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dir.y += 1.f;
	}
	return dir;
}
void Player::Shoot() {
	if (timer.getElapsedTime().asSeconds() > frate) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			std::cout << "+" <<std::endl;
			proj.push_back(Projectile(sprite.getPosition().x, sprite.getPosition().y - 0.2f));
			timer.restart();
		}
	}
	}