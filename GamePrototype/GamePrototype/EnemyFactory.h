#pragma once
#include "Enemy1.h"
#include "Enemy2.h"

class EnemyFactory
{
public:
	static Enemy* getEnemy(sf::Vector2f pos,std::string EnemyName) {
		if (EnemyName == "Enemy1")
			return new Enemy1(pos);
		else if (EnemyName == "Enemy2")
			return new Enemy2(pos);
		else
			return nullptr;
	}

};