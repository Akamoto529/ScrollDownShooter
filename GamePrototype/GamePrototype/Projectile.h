#pragma once
#include "Entity.h"

// Суперкласс для всех запускаемых снарядов.
class Projectile : public Entity
{
	int damage;
	// "Владелец" снаряда - игрок, враг, ...
	Entity* owner;
	// Вектор скорости снаряда (px/sec).
	sf::Vector2f velocity;
	void setVelocity(const sf::Vector2f direction);
	// Малое перемещение снаряда.
public:
	Projectile(const sf::Vector2f direction, const int damage, Entity* owner,
		const sf::Vector2f pos, const float speed, const int ID);
	static Projectile* createProjectile(const int ID, const sf::Vector2f pos, const sf::Vector2f direction, Entity* shooter);
	Entity* getOwner() const;
	sf::Vector2f getVelocity() const;
};

// Damage = 3; Speed = 800; Texture = bullet.
// Обычная пуля.
class Bullet : public Projectile
{
public:
	Bullet(const sf::Vector2f pos, const sf::Vector2f direction, Entity* shooter);
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