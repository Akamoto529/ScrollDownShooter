#pragma once
#include "Gun.h"
#include "Bullet.h"

class Rifle : public Gun
{
public:
	Rifle(const sf::Vector2f direction);
	std::list<Projectile*> shoot(const sf::Vector2f position);
};

