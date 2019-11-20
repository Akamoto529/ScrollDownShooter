#include "Projectile.h"
#include <cmath>

Projectile::Projectile(sf::Vector2f position, sf::Vector2f direction)
{
	this->setPosition(position);
	this->setVelocity(direction);
}

sf::Vector2f Projectile::getVelocity() { return this->velocity; }

void Projectile::step()
{
	this->move(this->velocity);
}

// Вычисляет единичный вектор направления и умножает на модуль скорости.
void Projectile::setVelocity(sf::Vector2f direction)
{
	float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	this->velocity.x = direction.x / length * speed;
	this->velocity.y = direction.y / length * speed;
}


Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
{
	this->setPosition(position);
	this->speed = 7.f;
	this->setVelocity(direction);
	this->bullet.setRadius(5.f);
	this->color = sf::Color::White;
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(this->bullet, states);
}

float Bullet::getDiameter()
{
	return 2*bullet.getRadius();
}
