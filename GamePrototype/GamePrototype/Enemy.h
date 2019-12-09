#pragma once
#include "Entity.h"
#include "Gun.h"
#include "Loader.h"

class Enemy : public Entity
{
	int health;
	Gun* gun;
public:
	Enemy(const sf::Vector2f pos);
	bool TakeDamage(const int dmg);
	std::list<Projectile*> Shoot() const;
	void step(const sf::Time dt);
};

