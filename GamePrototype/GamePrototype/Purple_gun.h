#pragma once
#include "Gun.h"
#include "Timer.h"

class Purple_gun : public Gun
{
private:
	Timer overheat;
public:
	Purple_gun(const sf::Vector2f direction);

	virtual void freeze() override;
	virtual void unfreeze() override;

	std::list<Projectile*> shoot(const sf::Vector2f position);
};