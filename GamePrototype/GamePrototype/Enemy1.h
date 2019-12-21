#pragma once
#include "Enemy.h"
#include "Rifle.h"
class Enemy1 : public Enemy
{
public:
	Enemy1(const sf::Vector2f pos);
	virtual void step(const sf::Time dt) override;
};

