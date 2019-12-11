#include "Level.h"
#include <fstream>
#include <sstream>
Level::Level() {
	EnemyTx[0].loadFromFile("Assets/Enemy.png");
	ProjectileTx[0].loadFromFile("Assets/Projectile.png");
}
void Level::Load(int Number) {
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
			waves[k].Enemies.push_back(Enemy(x, y, EnemyTx[0]));
			waves[k].Enemies[i].Path.push_back(sf::Vector2f(x, y));
			for (int j = 0; j < PointsAmount-1; j++) {
				fin >> x >> y;
				waves[k].Enemies[i].Path.push_back(sf::Vector2f(x,y));
			}
		}
	}
	fin.close();
	return;
}
std::string Level::IntToStr(int a) {
	std::stringstream ss;
	ss << a;
	std::string str = ss.str();
	return str;
}