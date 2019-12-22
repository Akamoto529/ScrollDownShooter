#pragma once
#include "Projectile.h"

class Bullet : public Projectile
{
public:
	Bullet(const sf::Vector2f pos, const sf::Vector2f direction, const int hostility);
	virtual void step(const sf::Time dt) override;
};