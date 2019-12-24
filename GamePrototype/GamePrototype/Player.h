#pragma once
#include <list>
#include "SFML/Graphics.hpp"
#include "config.h"
#include "Gun.h"
#include "Loader.h"
#include "Rifle.h"
#include "Missile.h"
#include "Timer.h"

// Gun = Rifle(Bullet); Health = 5; Speed = 400.
class Player : public Entity
{
private:
	Gun* gun;
	const int fullHP = 5;
	int HP;

	Timer shield;
	Timer overlay;

	void setHP(const int HP);
public:
	Player();

	const int getFullHP();
	int getHP() const;
	void heal();
	bool takeDamage(const int dmg);

	std::list<Projectile*> shoot() const;
	void step(const sf::Time dt);

	virtual void freeze() override;
	virtual void unfreeze() override;
};