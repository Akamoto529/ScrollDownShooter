#pragma once
#include <SFML/Graphics.hpp>
#include "Wave.h"
#include "Loader.h"
#include "EnemyFactory.h"
#include "Background.h"
#include "Entity.h"

class Level
{
private:
	Background* bg;
	bool frozen;
	Wave* waves;
	int wavesNumber;
public:
	Level();

	void Load(int Number, Entity* player);

	void freeze();
	void unfreeze();

	Background* getBG();
	std::list<Enemy*> getEnemies(int WaveNum);
	int getWavesNumber() const;
	float getWaveTime(int WaveNum);

	static std::string IntToStr(int a);
};

