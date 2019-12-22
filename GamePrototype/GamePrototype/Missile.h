#pragma once
#include "Projectile.h"

class Missile : Projectile
{
	Entity* target;
	float accuracy;
public:
	Missile(const sf::Vector2f direction, const int hostility, Entity* target, const sf::Vector2f pos);
	virtual void step(const sf::Time dt) override;
};