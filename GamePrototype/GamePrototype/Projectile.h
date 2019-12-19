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
		const sf::Vector2f pos, const float speed, const int ID);
	static Projectile* createProjectile(const int ID, const sf::Vector2f pos, const sf::Vector2f direction, const int hostility);
	int getDamage() const;
	int getHostility() const;
	sf::Vector2f getVelocity() const;
};

// Damage = 3; Speed = 800; Texture = bullet.
// Обычная пуля.
class Bullet : public Projectile
{
public:
	Bullet(const sf::Vector2f pos, const sf::Vector2f direction, const int hostility);
	virtual void step(const sf::Time dt) override;
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

class Sword : public Projectile
{

};