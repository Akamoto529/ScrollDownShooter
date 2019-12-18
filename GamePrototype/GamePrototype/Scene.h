#pragma once
#include <list>
#include "Projectile.h"
#include "Player.h"
#include "Loader.h"
#include "Enemy.h"
#include "Level.h"
#include "UI.h"

// Игровое поле.
class Scene : public sf::Drawable
{
	//UI ui;
	Player* player;

	Level lvl;
	// Размер игрового поля.
	sf::Vector2u WindowSize;
	// Списки игровых объектов для отслеживания.
	std::list<Enemy*> enemies;
	std::list<Projectile*> projectiles;
	//...

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	// Удаление объекта.
	std::list<Enemy*>::iterator DestroyEntity(std::list<Enemy*>::iterator pos);
	std::list<Projectile*>::iterator DestroyEntity(std::list<Projectile*>::iterator pos);
	// Проверка выхода за границы экрана.
	bool outOfBounds(const Entity* entity) const;
public:
	Scene();
	// Добавление объектов.
	void AddEntities(std::list<Enemy*> enemies);
	void AddEntities(std::list<Projectile*> projectiles);
	// ...

	void update(const sf::Time dt);
};