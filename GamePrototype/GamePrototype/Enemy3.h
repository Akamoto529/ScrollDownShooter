#pragma once
#include "Enemy.h"
#include "Rifle.h"

class Enemy3 : public Enemy
{
public:
	Enemy3(const sf::Vector2f pos);
	virtual void step(const sf::Time dt) override;
};
