#pragma once
#include <list>
#include "Gun.h"
#include "SFML/Graphics.hpp"
#include "Loader.h"
// Gun = Rifle(Bullet); Health = 5; Speed = 400.
class Player : public Entity
{
	Gun* gun;
	int health;
	void TakeDamage(const int dmg);
public:
	Player(sf::Vector2f pos);
	void step(const sf::Time dt);
	std::list<Projectile*> Shoot() const;
};