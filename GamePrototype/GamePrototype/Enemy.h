#pragma once
#include "Entity.h"
#include "Gun.h"
#include "Loader.h"

class Enemy : public Entity
{
	int health;
	Gun* gun;
	void TakeDamage(const int dmg);
public:
	Enemy(const sf::Vector2f pos);
	std::list<Projectile*> Shoot() const;
};

