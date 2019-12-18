#pragma once
#include "Entity.h"
#include "Gun.h"
#include "Loader.h"
#include <vector>

class Enemy : public Entity
{
private:
	int health;
	Gun* gun;
	int nextCheckpoint;
	std::vector<sf::Vector2f> Path;
public:
	Enemy(const sf::Vector2f pos);
	void addCheckpoint(const sf::Vector2f pos);
	std::list<Projectile*> shoot() const;
	void step(const sf::Time dt);
	bool TakeDamage(const int dmg);
};

