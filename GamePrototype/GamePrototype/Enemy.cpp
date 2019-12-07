#include "Enemy.h"
Enemy::Enemy(float x,float y,sf::Texture &tx) {
	this->curPoint = 0;
	this->Health = 6;
	this->speed = 1.f;
	this->sp.setTexture(tx);
	this->sp.setPosition(x, y);
	this->sp.setOrigin(tx.getSize().x / 2, 0.f);
}
sf::Vector2f Enemy::getDir() {

	return sf::Vector2f(0.f, 0.f);
}
void Enemy::Shoot() {
	gun.Shoot(sp.getPosition());
}
void Enemy::TakeDamage(int dmg) {
	Health -= dmg;
}
