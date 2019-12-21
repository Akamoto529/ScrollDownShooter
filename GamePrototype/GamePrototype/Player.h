#pragma once
#include <list>
#include "Gun.h"
#include "SFML/Graphics.hpp"
#include "Loader.h"
// Gun = Rifle(Bullet); Health = 5; Speed = 400.
class Player : public Entity
{
	Gun* gun;
	int HP;
	int fullHP;
public:
	Player();
	void step(const sf::Time dt);
	std::list<Projectile*> shoot() const;
	void TakeDamage(const int dmg);
	int getHP();
	int getFullHP();
};