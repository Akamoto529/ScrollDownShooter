#pragma once
#include "Enemy.h"
class Enemy2 :
	public Enemy
{
public:
	Enemy2(const sf::Vector2f pos);
	virtual void step(const sf::Time dt) override;
};