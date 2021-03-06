﻿#include "Projectile.h"

Projectile::Projectile(const sf::Vector2f direction, const int damage,
					   const sf::Vector2f pos, const float speed, const std::string Name)
	: Entity(pos, speed, Name)
{
	this->damage = damage;
	this->setRotation(direction);
	this->setVelocity(direction);
}

int Projectile::getDamage() const
{
	return this->damage;
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

void Projectile::step(const sf::Time dt)
{
	if (!frozen)
		this->move(dt.asSeconds() * this->getVelocity());
}