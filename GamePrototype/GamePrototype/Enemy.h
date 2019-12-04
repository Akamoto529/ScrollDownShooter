#pragma once
#include "Entity.h"
#include "Gun.h"
#include "Loader.h"

class Enemy : public Entity
{
	int health;
	Gun* gun;
	void TakeDamage(int dmg);
public:
	Enemy(sf::Texture& tx, sf::Vector2f pos, float hitboxRatio);
	std::list<Projectile*> Shoot();
};

