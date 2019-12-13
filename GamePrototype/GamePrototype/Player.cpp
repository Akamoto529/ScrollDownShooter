#include "Player.h"
Player::Player(){
	this->Health = 3;
	this->speed = 0.1f;
	this->tx.loadFromFile("Assets/2x/Blue_ani.png");
	this->sp.setTexture(tx);
	this->sp.setOrigin(tx.getSize().x / 2, 0.f);
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
	gun.Shoot(sp.getPosition());
	}