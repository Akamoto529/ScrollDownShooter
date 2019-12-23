#pragma once
#include <iostream>
#include <list>
#include "Background.h"
#include "Bonus.h"
#include "config.h"
#include "Collision.h"
#include "Enemy.h"
#include "Level.h"
#include "Loader.h"
#include "Player.h"
#include "Projectile.h"
#include "Timer.h"
#include "UI.h"

// Игровое поле.
class Scene : public sf::Drawable
{
private:
	int curWave;	//Отсчёт волн начинается с 1, а не с нуля. Если curWave равен нулю, то уровень ещё не начался 
	Background* bg;

	std::list<Bonus*> bonuses;
	std::list<Enemy*> enemies;
	std::list<Projectile*> EnemyProjs;
	std::list<Projectile*> PlayerProjs;

	Level lvl;
	Player* player;
	UI* ui;
	sf::Vector2u windowSize;

	Timer dtTimer;
	Timer WaveTimer;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool outOfBounds(const Entity* entity) const;
public:
	Scene();
	
	void LoadLevel(int LvlNum);

	void AddEntities(std::list<Bonus*> bonuses);
	void AddEntities(std::list<Enemy*> enemies);
	void AddEntities(std::list<Projectile*> projectiles);
	void AddEnemyProjs(std::list<Projectile*> projectiles);
	void AddPlayerProjs(std::list<Projectile*> projectiles);

	void freeze();
	void unfreeze();

	void update();
};