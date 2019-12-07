#pragma once
#include <list>
#include "Projectile.h"
#include "Player.h"
#include "Loader.h"
#include "Enemy.h"

// Игровое поле.
class Scene : public sf::Drawable
{
	// Загрузка ресурсов.
	Loader* loader;
	// Размер игрового поля.
	sf::Vector2u size;
	// Списки игровых объектов для отслеживания.
	Player* player;
	std::list<Enemy*> enemies;
	std::list<Projectile*> projectiles;
	//...

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	// Удаление объекта при смерти или выходе за экран.
	std::list<Projectile*>::iterator DestroyEntity(std::list<Projectile*>::iterator pos);
	// Проверка выхода за границы экрана.
	bool outOfBounds(const Entity* entity) const;
public:
	Scene();
	// Добавление объектов.
	void AddEntity(Enemy* enemy);
	void AddEntity(Projectile* projectile);
	// ...

	void update(const sf::Time dt);
};