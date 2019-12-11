#include "Enemy.h"
#include <iostream>
Enemy::Enemy(float x,float y,sf::Texture &tx) {
	this->curPoint = 0;
	this->Health = 6;
	this->speed = 0.05f;
	this->sp.setTexture(tx);
	this->sp.setPosition(x, y);
	this->sp.setOrigin(tx.getSize().x / 2, 0.f);
}
void Enemy::Shoot() {
	gun.Shoot(sp.getPosition());
}
void Enemy::TakeDamage(int dmg) {
	Health -= dmg;
}
void Enemy::move(float frametime) {
	if (curPoint < Path.size()-1) {
		float x = Path[curPoint + 1].x - Path[curPoint].x;
		float y = Path[curPoint + 1].y - Path[curPoint].y;
		float length = sqrt(x * x + y * y);
		if ((abs(x / length * speed) > abs(Path[curPoint + 1].x - sp.getPosition().x)) || (abs(y / length * speed) > abs(Path[curPoint + 1].y - sp.getPosition().y))) {
			curPoint++;
			sp.setPosition(Path[curPoint].x,Path[curPoint].y);
		}
		else {
			sp.move(sf::Vector2f(x / length, y / length) * speed*frametime);
		}
	}
}
