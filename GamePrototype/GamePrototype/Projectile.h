#pragma once
#include "Entity.h"

// Суперкласс для всех запускаемых снарядов.
class Projectile : public Entity
{
	// Вектор скорости снаряда.
	sf::Vector2f velocity;
protected:
	// Модуль скорости.
	float speed;
public:
	Projectile(sf::Vector2f position = sf::Vector2f(0, 0),
		sf::Vector2f direction = sf::Vector2f(0, 0));
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f direction);
    // Малое перемещение снаряда.
    void step();
};

// Круглая пуля.
class Bullet : public Projectile
{
	sf::CircleShape bullet;
	sf::Color color;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Bullet(sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f direction = sf::Vector2f(0, 0));
	float getDiameter() override;

};
