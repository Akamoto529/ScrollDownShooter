#pragma once
#include <list>
#include "Projectile.h"
#include "Player.h"
#include "Loader.h"
#include "Enemy.h"
#include "Level.h"
#include "UI.h"
#include "Background.h"
#include "Bonus.h"
#include "Timer.h"

// Игровое поле.
class Scene : public sf::Drawable
{
	Timer WaveTimer;
	int curWave;	//Отсчёт волн начинается с 1, а не с нуля. Если curWave равен нулю, то уровень ещё не начался 
	Background* bg;
	std::list<Bonus*> bonuses;
	std::list<Enemy*> enemies;
	UI *ui;
	Player* player;
	Level lvl;
	std::list<Projectile*> PlayerProjs;
	std::list<Projectile*> EnemyProjs;
	sf::Vector2u windowSize;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	// Проверка выхода за границы экрана.
	bool outOfBounds(const Entity* entity) const;
public:
	Scene();
	void LoadLevel(int LvlNum);
	void AddEntities(std::list<Bonus*> bonuses);
	void AddEntities(std::list<Enemy*> enemies);
	void AddEntities(std::list<Projectile*> projectiles);
	void AddPlayerProjs(std::list<Projectile*> projectiles);
	void AddEnemyProjs(std::list<Projectile*> projectiles);
	void update(const sf::Time dt);
};