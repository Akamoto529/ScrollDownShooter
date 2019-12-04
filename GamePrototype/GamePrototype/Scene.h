#pragma once
#include <list>
#include "Projectile.h"
#include "Player.h"
#include "Loader.h"
#include "Enemy.h"

// Игровое поле.
class Scene : public sf::Drawable
{
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
	bool outOfBounds(Entity* entity);
public:
	Scene(sf::Vector2u windowSize = sf::Vector2u(0,0));
	// Добавление объектов.
	void AddEntity(Projectile* projectile);
	// ...

	void update();
};