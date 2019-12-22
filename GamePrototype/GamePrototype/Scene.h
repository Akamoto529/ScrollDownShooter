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
	Background* bg;
	std::list<Bonus*> bonuses;
	std::list<Enemy*> enemies;
	UI *ui;
	Player* player;

	Level lvl;
	std::list<Projectile*> projectiles;
	//UI ui;
	// Размер игрового поля.
	sf::Vector2u windowSize;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	// Проверка выхода за границы экрана.
	bool outOfBounds(const Entity* entity) const;
public:
	Scene();
	// Добавление объектов.
	void AddEntities(std::list<Bonus*> bonuses);
	void AddEntities(std::list<Enemy*> enemies);
	void AddEntities(std::list<Projectile*> projectiles);
	void update(const sf::Time dt);
};