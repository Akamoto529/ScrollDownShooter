#pragma once
#include "Gun.h"

class Launcher : public Gun
{
private:
	Entity* target;
public:
	Launcher(const sf::Vector2f direction, Entity* target);
	std::list<Projectile*> shoot(const sf::Vector2f position);
};