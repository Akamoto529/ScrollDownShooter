#pragma once
#include <list>
#include "Gun.h"
#include "SFML/Graphics.hpp"
#include "Loader.h"

class Player : public Entity
{
	Gun* gun;
	int health;
	void TakeDamage(int dmg);
public:
	Player(sf::Texture& tx, float speed, sf::Vector2f pos, float hitboxRatio);
	void move();
	std::list<Projectile*> Shoot();
};

