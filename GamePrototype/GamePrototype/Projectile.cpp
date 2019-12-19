#include "Projectile.h"
#include "Loader.h"
#include <cmath>

// Projectile.

// Использует конструктор класса Entity.
Projectile::Projectile(const sf::Vector2f direction, const int damage, const  int hostility,
					   const sf::Vector2f pos, const float speed, const std::string Name)
	: Entity(pos, speed, Name)
{
	this->damage = damage;
	this->setVelocity(direction);
	this->hostility = hostility;
}
 void Projectile::step(const sf::Time dt) {

}
int Projectile::getDamage() const
{
	return this->damage;
}

int Projectile::getHostility() const
{
	return this->hostility;
}

sf::Vector2f Projectile::getVelocity() const
{ 
	return this->velocity;
}

// Вычисляет единичный вектор направления и умножает на модуль скорости.
void Projectile::setVelocity(const sf::Vector2f direction)
{
	float length = sqrt(direction.x*direction.x + direction.y * direction.y);
	this->velocity.x = direction.x / length * this->speed;
	this->velocity.y = direction.y / length * this->speed;
}