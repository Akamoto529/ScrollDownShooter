#pragma once
#include "Projectile.h"

class Missile : public Projectile
{
	Entity* target;
	float accuracy;
public:
	Missile(const sf::Vector2f pos, const sf::Vector2f direction, Entity* target);
	virtual void step(const sf::Time dt) override;
};