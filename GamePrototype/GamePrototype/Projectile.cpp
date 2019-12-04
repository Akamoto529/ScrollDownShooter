#include "Projectile.h"
#include <cmath>

// Использует конструктор класса Entity.
Projectile::Projectile(sf::Vector2f direction, sf::Texture& tx, float speed, sf::Vector2f pos, float hitboxRatio)
	: Entity(tx, speed, pos, hitboxRatio)
{
	this->damage = 1;
	this->setVelocity(direction);
}

sf::Vector2f Projectile::getVelocity()
{ 
	return this->velocity;
}

// Вычисляет единичный вектор направления и умножает на модуль скорости.
void Projectile::setVelocity(sf::Vector2f direction)
{
	float length = sqrt(direction.x*direction.x + direction.y * direction.y);
	this->velocity.x = direction.x / length * this->speed;
	this->velocity.y = direction.y / length * this->speed;
}

void Projectile::step(sf::Time dt)
{
	this->move((float)dt.asMilliseconds()*this->velocity);
}

// (старая версия)
//Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
//{
//	this->setPosition(position);
//	this->speed = 7.f;
//	this->setVelocity(direction);
//	this->bullet.setRadius(5.f);
//	this->color = sf::Color::White;
//}
//
//void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	states.transform *= getTransform();
//	target.draw(this->bullet, states);
//}
//
//float Bullet::getDiameter()
//{
//	return 2*bullet.getRadius();
//}
