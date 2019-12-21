#pragma once
#include <list>
#include "Gun.h"
#include "SFML/Graphics.hpp"
#include "Loader.h"
// Gun = Rifle(Bullet); Health = 5; Speed = 400.
class Player : public Entity
{
	Gun* gun;
	const int fullHP = 5;
	int HP;
public:
	Player();
	const int getFullHP();
	int getHP() const;
	bool takeDamage(const int dmg);
	std::list<Projectile*> shoot() const;
	void step(const sf::Time dt);
};