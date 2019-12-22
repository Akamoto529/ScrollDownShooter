#include "Level.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include <fstream>
#include <sstream>
Level::Level() {}
void Level::Load(int Number) {
	std::string path = "Levels/Lvl" + IntToStr(Number) + "/LvlInfo.txt";
	std::ifstream fin(path);
	std::string Type;
	int WaveAmount,EnemyAmount,PointsAmount, x, y;
	fin >> WaveAmount;
	waves = new Wave[WaveAmount];
	std::string bgTX;
	int bgSpeed;
	fin >>bgSpeed >> bgTX;
	bg = new Background(bgSpeed, bgTX);
	for (int k = 0; k < WaveAmount; k++) {
		fin.close();
		fin.open("Levels/Lvl" + IntToStr(Number) + "/Wave" + IntToStr(k + 1) + ".txt");
		fin >> waves[k].Time;
		fin >> EnemyAmount;
		for (int i = 0; i < EnemyAmount; i++)
		{
			fin >> Type;
			fin >> PointsAmount;
			fin >> x >> y;
			waves[k].Enemies.push_back(EnemyFactory::getEnemy(sf::Vector2f(x, y),Type));
			Enemy*& en = waves[k].Enemies.back();
			for (int j = 0; j < PointsAmount-1; j++) {
				fin >> x >> y;
				en->addPoint(sf::Vector2f(x, y));
			}
		}
	}
	fin.close();
	return;
}
Background* Level::getBG() {
	return this->bg;
}
std::list<Enemy*> Level::getEnemies(int WaveNum) {
	return waves[WaveNum].Enemies;
}
int Level::getWaveTime(int WaveNum) {
	return waves[WaveNum].Time;
}
std::string Level::IntToStr(int a) {
	std::stringstream ss;
	ss << a;
	std::string str = ss.str();
	return str;
}