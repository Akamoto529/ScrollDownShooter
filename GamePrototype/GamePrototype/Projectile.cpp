#include "Projectile.h"
Projectile::Projectile(float x, float y) {
	this->dir = sf::Vector2f(0.f, -1.f);
	this->speed = 0.15f;
	this->tx.loadFromFile("Assets/Projectile.png");
	this->sprite.setTexture(tx);
	this->sprite.setOrigin(tx.getSize().x / 2, tx.getSize().y / 2);
	this->sprite.setPosition(x, y);
}
Projectile::Projectile(const Projectile& obj) {
	this->sprite = obj.sprite;
	this->dir = obj.dir;
	this->speed = obj.speed;
	this->tx.loadFromFile("Assets/Projectile.png");
	this->sprite.setTexture(tx);
}