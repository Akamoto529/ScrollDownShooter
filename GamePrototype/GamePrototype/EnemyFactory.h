#pragma once
#include "Blue_enemy.h"
#include "Purple_enemy.h"
#include "Suicider.h"
#include "Turret.h"
#include <iostream>

class EnemyFactory
{
public:
	static Enemy* getEnemy(sf::Vector2f pos,std::string EnemyName, Entity* target = nullptr) {
		if (EnemyName == "Blue_enemy")
			return new Blue_enemy(pos);
		else if (EnemyName == "Purple_enemy")
			return new Purple_enemy(pos);
		else if (EnemyName == "Suicider")
			return new Suicider(pos, target);
		else if (EnemyName == "Turret")
			return new Turret(pos, target);
		else
		{
			std::cout << "Enemy " << EnemyName << " not loaded\n";
			return nullptr;
		}
	}

};