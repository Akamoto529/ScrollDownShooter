#pragma once
#include "Entity.h"
#include "Gun.h"
#include "Loader.h"
#include<vector>

class Enemy : public Entity
{
private:
	int curPoint;
	int health;
	Gun* gun;
public:
	std::vector<sf::Vector2f> Path;
	Enemy(const sf::Vector2f pos);
	bool TakeDamage(const int dmg);
	std::list<Projectile*> Shoot() const;
	void step(const sf::Time dt);
};

