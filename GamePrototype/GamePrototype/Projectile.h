#pragma once
#include "Entity.h"

// Суперкласс для всех запускаемых снарядов.
class Projectile : public Entity
{
private:
	int damage;
	// hostile, friendly, neutral.
	int hostility;
	// Вектор скорости снаряда (px/sec).
	sf::Vector2f velocity;
	void setVelocity(const sf::Vector2f direction);
public:
	Projectile(const sf::Vector2f direction, const int damage, const int hostility,
		const sf::Vector2f pos, const float speed, const std::string Name);
	int getDamage() const;
	int getHostility() const;
	sf::Vector2f getVelocity() const;
};

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