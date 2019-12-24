#pragma once
#include "Entity.h"
#include "Enemy.h"

class Suicider : public Enemy
{
private:
	Entity* target;
public:
	Suicider(const sf::Vector2f pos, Entity* target);
	virtual void step(const sf::Time dt) override;
};