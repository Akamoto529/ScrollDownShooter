#include "Level.h"
#include <fstream>
Level::Level(std::string filename) {
	EnemyTx[0].loadFromFile("Assets/Enemy.png");
	ProjectileTx[0].loadFromFile("Assets/Projectile.png");
}
void Level::LoadWave() {
	std::string path = "Levels/Lvl1/Wave1.txt";
	std::ifstream fin(path);
	int amount, x, y;
	fin >> amount;
	for (int i = 0; i < amount; i++)
	{
		fin >> x >> y;
		waves[0].enemies.push_back(Enemy(x, y,EnemyTx[0]));
	}
	fin.close();
	return;
}