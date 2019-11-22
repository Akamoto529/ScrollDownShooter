#include "Enemy.h"
Enemy::Enemy(float x,float y) {
	this->Health = 6;
	this->speed = 0.f;
	this->tx.loadFromFile("Assets/Enemy.png");
	this->sp.setTexture(tx);
	this->sp.setPosition(x, y);
	this->sp.setOrigin(tx.getSize().x / 2, 0.f);
}
sf::Vector2f Enemy::getDir() {
	sf::Vector2f dir = sf::Vector2f(0.f, 0.f);
	return dir;
}
void Enemy::Shoot() {
	gun.Shoot(sp.getPosition());
}
void Enemy::TakeDamage(int dmg) {
	Health -= dmg;
}
