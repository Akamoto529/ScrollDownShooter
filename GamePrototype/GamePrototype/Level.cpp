#include "Level.h"
#include "Blue_enemy.h"
#include "Purple_enemy.h"
#include <fstream>
#include <sstream>

Level::Level() 
{
	bg = nullptr;
	waves = nullptr;
}

void Level::Load(int Number, Entity* player)
	{
	std::string path = "Levels/Lvl" + IntToStr(Number) + "/LvlInfo.txt";
	std::ifstream fin(path);
	std::string Type;
	int WaveNumber,EnemyNumber,PointsNumber, x, y;
	fin >> WaveNumber;
	this->wavesNumber = WaveNumber;
	waves = new Wave[WaveNumber];
	std::string bgTX;
	int bgSpeed;
	fin >>bgSpeed >> bgTX;
	Background::setSpeed((float)bgSpeed);
	bg = new Background(bgTX);
	for (int k = 0; k < WaveNumber; k++) {
		fin.close();
		fin.open("Levels/Lvl" + IntToStr(Number) + "/Wave" + IntToStr(k + 1) + ".txt");
		fin >> waves[k].time;
		fin >> EnemyNumber;
		for (int i = 0; i < EnemyNumber; i++)
		{
			fin >> Type;
			fin >> PointsNumber;
			fin >> x >> y;
			waves[k].Enemies.push_back(EnemyFactory::getEnemy(sf::Vector2f((float)x, (float)y),Type,player));
			Enemy*& en = waves[k].Enemies.back();
			for (int j = 0; j < PointsNumber-1; j++) {
				fin >> x >> y;
				en->addPoint(sf::Vector2f((float)x, (float)y));
			}
		}
	}
	fin.close();
	return;
}

void Level::freeze()
{
	this->frozen = true;

}

Background* Level::getBG()
{
	return this->bg;
}

std::list<Enemy*> Level::getEnemies(int WaveNum)
{
	return waves[WaveNum].Enemies;
}

int Level::getWavesNumber() const
{
	return this->wavesNumber;
}

float Level::getWaveTime(int WaveNum)
{
	return waves[WaveNum].time;
}

std::string Level::IntToStr(int a)
{
	std::stringstream ss;
	ss << a;
	std::string str = ss.str();
	return str;
}