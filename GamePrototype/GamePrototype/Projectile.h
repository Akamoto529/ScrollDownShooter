#pragma once
#include "Entity.h"

// Суперкласс для всех запускаемых снарядов.
class Projectile : public Entity
{
	int damage;
	// hostile, friendly, neutral.
	int hostility;
	// Вектор скорости снаряда (px/sec).
	sf::Vector2f velocity;
	void setVelocity(const sf::Vector2f direction);
	// Малое перемещение снаряда.
public:
	Projectile(const sf::Vector2f direction, const int damage, const int hostility,
		const sf::Vector2f pos, const float speed, const std::string Name);
	virtual void step(const sf::Time dt);
	int getDamage() const;
	int getHostility() const;
	sf::Vector2f getVelocity() const;
};

// Damage = 3; Speed = 800; Texture = bullet.
// Обычная пуля.

class Grenade : public Projectile
{

};

class Needle : public Projectile
{

};

class Laser : public Projectile
{

};

class Homing : public Projectile
{

};

class Sword : public Projectile
{

};