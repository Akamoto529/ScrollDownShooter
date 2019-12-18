#pragma once
#include <SFML/Graphics.hpp>
#include "Wave.h"
#include "Loader.h"
class Level
{
private:
	int curWave;
public:
	Wave *waves;
	void Load(int Number);
	std::string IntToStr(int a);
	Level();
	std::list<Enemy*> getEnemies();
};

