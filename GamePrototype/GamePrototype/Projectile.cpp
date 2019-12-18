#include "Projectile.h"
#include "Loader.h"
#include <cmath>
#include <iostream>


// Projectile.


// Использует конструктор класса Entity.
Projectile::Projectile(const sf::Vector2f direction, const int damage, const  int hostility,
	const sf::Vector2f pos, const float speed, const int ID)
	: Entity(pos, speed, ID)
{
	this->damage = damage;
	this->setVelocity(direction);
	this->hostility = hostility;
}

Projectile* Projectile::createProjectile(const int ID, const sf::Vector2f pos, const sf::Vector2f direction, const int hostility)
{
	Projectile* p = 0;
	switch (ID)
	{
	case (bullet_ID):
		p = new Bullet(pos, direction, hostility);
		break;
	default:
		std::cout << "Неправильный код снаряда" << std::endl;
		break;
	}
	return p;
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


// Bullet.


Bullet::Bullet(const sf::Vector2f pos, const sf::Vector2f direction, const int hostility)
	: Projectile(direction, 3, hostility, pos, 800.f, bullet_ID)
{};

void Bullet::step(const sf::Time dt)
{
	this->move((float)dt.asMicroseconds() / 1000000 * this->getVelocity());
}