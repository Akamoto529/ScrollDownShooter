#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f pos, float speed, std::string Name)
	: Entity(pos, speed, Name)
{
	this->nextPoint = 0;
	this->HP = 0;
	this->gun = nullptr;
};

void Enemy::addPoint(const sf::Vector2f pos)
{
	this->Path.push_back(pos);
}

std::list<Projectile*> Enemy::shoot() const
{
	if (gun != nullptr)
		return gun->shoot(this->getPosition());
	else
		return {};
}

void Enemy::freeze()
{
	this->Entity::freeze();
	if (this->gun != nullptr)
		this->gun->freeze();
}

bool Enemy::takeDamage(const int dmg)
{
	this->HP -= dmg;
	if (this->HP <= 0)
		// Удаление происходит в сцене, не здесь.
		return 0;
	else
		return 1;
}

void Enemy::unfreeze()
{
	this->Entity::unfreeze();
	if (this->gun != nullptr)
		this->gun->unfreeze();
}