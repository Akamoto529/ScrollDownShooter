#pragma once
#include "Enemy.h"

class Invader : public Enemy
{
private:
	sf::Vector2f startPos;
public:
	Invader(sf::Vector2f pos);
	void step(sf::Time dt);
};

