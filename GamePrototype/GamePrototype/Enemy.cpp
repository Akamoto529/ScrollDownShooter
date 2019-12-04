#include "Enemy.h"

Enemy::Enemy(sf::Texture& tx, sf::Vector2f pos, float hitboxRatio)
	: Entity(tx, 2, pos, hitboxRatio)
{
	gun = new Rifle(sf::Vector2f(0, 1), Loader::getInstance()->GetProjectile());
	health = 2;
}

void Enemy::TakeDamage(int dmg)
{
	this->health -= dmg;
}

std::list<Projectile*> Enemy::Shoot()
{
	return gun->Shoot(this->getPosition());
}