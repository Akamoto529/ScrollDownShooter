#include "Level.h"
#include <fstream>
#include <sstream>
Level::Level() {
}
void Level::Load(int Number) {
	curWave = 0;
	std::string path = "Levels/Lvl" + IntToStr(Number) + "/LvlInfo.txt";
	std::ifstream fin(path);
	int WaveAmount,EnemyAmount,PointsAmount, x, y;
	fin >> WaveAmount;
	waves = new Wave[WaveAmount];
	for (int k = 0; k < WaveAmount; k++) {
		fin.close();
		fin.open("Levels/Lvl" + IntToStr(Number) + "/Wave" + IntToStr(k + 1) + ".txt");
		fin >> EnemyAmount;
		for (int i = 0; i < EnemyAmount; i++)
		{
			fin >> PointsAmount;
			fin >> x >> y;
			waves[k].Enemies.push_back(new Enemy(sf::Vector2f(x, y)));
			Enemy*& en = waves[k].Enemies.back();
			en->Path.push_back(sf::Vector2f(x, y));
			for (int j = 0; j < PointsAmount-1; j++) {
				fin >> x >> y;
				en->Path.push_back(sf::Vector2f(x, y));
			}
		}
	}
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