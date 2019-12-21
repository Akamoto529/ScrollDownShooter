#pragma once
#include "Entity.h"
#include "Gun.h"
#include "config.h"
#include "Loader.h"
#include <vector>

class Enemy : public Entity
{
protected:
	int HP;
	Gun* gun;
	int nextPoint;
	std::vector<sf::Vector2f> Path;
public:
	Enemy(const sf::Vector2f pos, std::string Name);
	void addPoint(const sf::Vector2f pos);
	std::list<Projectile*> shoot() const;
	virtual void step(const sf::Time dt);
	bool TakeDamage(const int dmg);
};

