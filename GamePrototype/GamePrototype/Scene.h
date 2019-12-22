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
	Background* bg;
	std::list<Bonus*> bonuses;
	std::list<Enemy*> enemies;
	Level lvl;
	Player* player;
	std::list<Projectile*> projectiles;
	//UI ui;
	sf::Vector2u windowSize;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool outOfBounds(const Entity* entity) const;
public:
	Scene();
	void AddEntities(std::list<Bonus*> bonuses);
	void AddEntities(std::list<Enemy*> enemies);
	void AddEntities(std::list<Projectile*> projectiles);
	void freeze();
	void unfreeze();
	void update(const sf::Time dt);
};