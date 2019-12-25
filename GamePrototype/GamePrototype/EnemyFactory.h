#pragma once
#include "Blue_enemy.h"
#include "Green_enemy.h"
#include "Purple_enemy.h"
#include "Grey_enemy.h"
#include "Suicider.h"
#include "Turret.h"
#include "Invader.h"
#include <iostream>

class EnemyFactory
{
public:
	static Enemy* getEnemy(sf::Vector2f pos,std::string EnemyName, Entity* target = nullptr) {
		if (EnemyName == "Blue_enemy")
			return new Blue_enemy(pos);
		if (EnemyName == "Green_enemy")
			return new Green_enemy(pos);
		else if (EnemyName == "Purple_enemy")
			return new Purple_enemy(pos);
		else if (EnemyName == "Suicider")
			return new Suicider(pos, target);
		else if (EnemyName == "Turret")
			return new Turret(pos, target);
		else if (EnemyName == "Grey_enemy")
			return new Grey_enemy(pos);
		else if (EnemyName == "Invader")
			return new Invader(pos);
		else
		{
			std::cout << "Enemy " << EnemyName << " not loaded\n";
			return nullptr;
		}
	}

};