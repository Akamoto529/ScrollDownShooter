#pragma once
#include "Projectile.h"

class Bullet : public Projectile
{
public:
	Bullet(const sf::Vector2f pos, const sf::Vector2f direction);
};