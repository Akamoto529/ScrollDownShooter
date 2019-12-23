#include "Level.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include <fstream>
#include <sstream>
Level::Level() {
	this->curWave = 0;
}
void Level::Load(int Number, Entity* player) {
	curWave = 0;
	std::string path = "Levels/Lvl" + IntToStr(Number) + "/LvlInfo.txt";
	std::ifstream fin(path);
	std::string Type;
	int WaveAmount,EnemyAmount,PointsAmount, x, y;
	fin >> WaveAmount;
	waves = new Wave[WaveAmount];
	for (int k = 0; k < WaveAmount; k++) {
		fin.close();
		fin.open("Levels/Lvl" + IntToStr(Number) + "/Wave" + IntToStr(k + 1) + ".txt");
		fin >> EnemyAmount;
		for (int i = 0; i < EnemyAmount; i++)
		{
			fin >> Type;
			fin >> PointsAmount;
			fin >> x >> y;
			waves[k].Enemies.push_back(EnemyFactory::getEnemy(sf::Vector2f(x, y),Type,player));
			Enemy*& en = waves[k].Enemies.back();
			for (int j = 0; j < PointsAmount-1; j++) {
				fin >> x >> y;
				en->addPoint(sf::Vector2f(x, y));
			}
		}
	}
	waves[0].Enemies.push_back(EnemyFactory::getEnemy(sf::Vector2f(100, 100), "Turret", player));
	fin.close();
	return;
}
std::list<Enemy*> Level::getEnemies() {
	return waves[curWave].Enemies;
}

std::string Level::IntToStr(int a) {
	std::stringstream ss;
	ss << a;
	std::string str = ss.str();
	return str;
}