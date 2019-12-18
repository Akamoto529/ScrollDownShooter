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
	const int fullHP=5;
	void TakeDamage(const int dmg);
public:
	Player();
	void step(const sf::Time dt);
	std::list<Projectile*> shoot() const;
	int getHP();
	const int getFullHP();
};