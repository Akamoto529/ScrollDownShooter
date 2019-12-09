#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f pos)
	: Entity(pos, 400.f, enemy2_ID)
{
	gun = new Rifle(sf::Vector2f(0, 1), bullet_ID, this);
	health = 10;
}

bool Enemy::TakeDamage(const int dmg)
{
	this->health -= dmg;
	if (this->health <= 0)
		// Удаление происходит в сцене, не здесь.
		return 0;
	return 1;
}

std::list<Projectile*> Enemy::Shoot() const
{
	return gun->Shoot(this->getPosition());
}

void Enemy::step(sf::Time dt)
{

}