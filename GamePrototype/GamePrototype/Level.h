#pragma once
#include <SFML/Graphics.hpp>
#include "Wave.h"
#include "Loader.h"
#include "EnemyFactory.h"
class Level
{
private:
	int curWave;
public:
	Wave *waves;
	void Load(int Number, Entity* player);
	std::string IntToStr(int a);
	Level();
	std::list<Enemy*> getEnemies();
};

