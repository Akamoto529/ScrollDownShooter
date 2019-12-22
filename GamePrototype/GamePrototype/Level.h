#pragma once
#include <SFML/Graphics.hpp>
#include "Wave.h"
#include "Loader.h"
#include "EnemyFactory.h"
#include "Background.h"
class Level
{
private:
	Wave* waves;
	Background* bg;
public:
	void Load(int Number);
	std::string IntToStr(int a);
	Level();
	int getWaveTime(int WaveNum);
	Background* getBG();
	std::list<Enemy*> getEnemies(int WaveNum);
};

