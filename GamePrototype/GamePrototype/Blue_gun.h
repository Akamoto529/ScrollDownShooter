#pragma once
#include "Gun.h"

class Blue_gun : public Gun
{
public:
	Blue_gun(const sf::Vector2f direction);
	std::list<Projectile*> shoot(const sf::Vector2f position);
};

