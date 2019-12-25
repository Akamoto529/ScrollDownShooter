#pragma once
#include "Gun.h"

class Green_gun : public Gun
{
public:
	Green_gun(const sf::Vector2f direction);
	std::list<Projectile*> shoot(const sf::Vector2f position);
};