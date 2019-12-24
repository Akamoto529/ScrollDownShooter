#pragma once
#include "Background.h"
#include "Enemy.h"
#include "Launcher.h"

class Turret : public Enemy
{
private:
	Entity* target;
public:
	Turret(const sf::Vector2f pos, Entity* target);
	virtual void step(const sf::Time dt) override;
};