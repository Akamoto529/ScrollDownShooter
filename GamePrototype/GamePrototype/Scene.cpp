#include "Scene.h"
#include <iostream>
#include "config.h"
#include "Collision.h"

Scene::Scene()
{
	size.x = (uint16_t)WINDOW_X;
	size.y = (uint16_t)WINDOW_Y;

	player = new Player(sf::Vector2f(WINDOW_X/2, WINDOW_Y - 100));
	enemies = {};
	enemies.push_back(new Enemy(sf::Vector2f(400, 400)));
	enemies.push_back(new Enemy(sf::Vector2f(350, 400)));
	enemies.push_back(new Enemy(sf::Vector2f(300, 400)));
	enemies.push_back(new Enemy(sf::Vector2f(450, 400)));
	enemies.push_back(new Enemy(sf::Vector2f(400, 470)));
	projectiles = {};
	// ...
}

void Scene::AddEntity(Projectile* projectile)
{
	projectiles.push_back(projectile);
}

// Уничтожает объект по ссылке и удаляет ссылку на него из списка.
std::list<Projectile*>::iterator Scene::DestroyEntity(std::list<Projectile*>::iterator pos)
{
	delete* pos;
	return this->projectiles.erase(pos);
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (Projectile* projectile : this->projectiles)
	{
		target.draw(*projectile, states);
	}
	// ...
	for (Enemy* enemy : this->enemies)
	{
		target.draw(*enemy, states);
	}

	target.draw(*player, states);
}

bool Scene::outOfBounds(const Entity* entity) const
{
	sf::FloatRect box = entity->getGlobalBounds();
	if (box.top+box.height < 0
		|| box.left+box.width < 0
		|| box.top > this->size.y
		|| box.left > this->size.x)
		return 1;
	return 0;
}

void Scene::update(sf::Time dt)
{
	player->step(dt);

	// Утечка памяти?
	// Запись в обход AddEntity!
	projectiles.splice(projectiles.end(), player->Shoot());
	/*for (Enemy* enemy : this->enemies)
	{
		projectiles.splice(projectiles.end(), enemy->Shoot());
	}*/

	for (Projectile* projectile : this->projectiles)
		projectile->step(dt);

	for(auto i = projectiles.begin(); i != projectiles.end(); ++i)
	{
		if (outOfBounds(*i))
		{
			i = DestroyEntity(i);
			continue;
		}

		for (auto j = enemies.begin(); j != enemies.end(); ++j)
		{
			if (typeid(*i == typeid(Player)  && Collision::RectangleTest(projectile, enemy))
			{
				i = DestroyEntity(i);
				break;
			}
		}
		if (this->projectiles.empty())
			break;
	}
}