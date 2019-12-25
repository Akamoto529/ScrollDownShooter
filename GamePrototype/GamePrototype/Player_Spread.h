#pragma once
#include "Gun.h"

class Player_Spread : public Gun
{
public:
	Player_Spread(const sf::Vector2f direction);
	std::list<Projectile*> shoot(const sf::Vector2f position);
};
