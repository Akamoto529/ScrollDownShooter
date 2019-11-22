#include "Projectile.h"
Projectile::Projectile(float x, float y,sf::Texture& tx) {
	this->dir = sf::Vector2f(0.f, -1.f);
	this->speed = 0.15f;
	this->sp.setTexture(tx);
	this->sp.setOrigin(tx.getSize().x / 2, tx.getSize().y / 2);
	this->sp.setPosition(x, y);
}