#pragma once
#include "Entity.h"

// Суперкласс для всех запускаемых снарядов.
class Projectile : public Entity
{
private:
	int damage;
	// hostile, friendly, neutral.
	// Вектор скорости снаряда (px/sec).
	sf::Vector2f velocity;
protected:
	void setVelocity(const sf::Vector2f direction);
public:
	Projectile(const sf::Vector2f direction, const int damage,
		const sf::Vector2f pos, const float speed, const std::string Name);
	int getDamage() const;
	int getHostility() const;
	sf::Vector2f getVelocity() const;
};

class Laser : public Projectile
{

};