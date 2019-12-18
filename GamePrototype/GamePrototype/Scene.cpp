#include "Scene.h"
#include <iostream>
#include "config.h"
#include "Collision.h"
#include <typeinfo>

Scene::Scene()
{
	this->WindowSize.x = (uint16_t)WINDOW_X;
	this->WindowSize.y = (uint16_t)WINDOW_Y;
	this->enemies = {};
	this->projectiles = {};
	this->lvl.Load(1);
	this->player = new Player();
	AddEntities(lvl.getEnemies());
}

void Scene::AddEntities(std::list<Enemy*> enemies)
{
	for (Enemy* enemy : enemies)
		this->enemies.push_back(enemy);
}

void Scene::AddEntities(std::list<Projectile*> projectiles)
{
	for (Projectile* projectile : projectiles)
	this->projectiles.push_back(projectile);
}

std::list<Enemy*>::iterator Scene::DestroyEntity(std::list<Enemy*>::iterator pos)
{
	delete* pos;
	return this->enemies.erase(pos);
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
		|| box.top > this->WindowSize.y
		|| box.left > this->WindowSize.x)
		return 1;
	return 0;
}

void Scene::update(sf::Time dt)
{
	player->step(dt);
	AddEntities(player->Shoot());
	for (auto i = this->enemies.begin(); i != this->enemies.end(); ++i)
	{
		auto& enemy = *i;
		//if (enemy == nullptr)
		//	i = DestroyEntity(i);
		//else {
			enemy->step(dt);
			AddEntities(enemy->Shoot());
		//}
	}
	for (auto i = this->projectiles.begin(); i != this->projectiles.end(); ++i)
	{
		auto& projectile = *i;
		projectile->step(dt);
		if (outOfBounds(projectile))
		{
			i = DestroyEntity(i);
			continue;
		}

		if (projectile->getOwner() == this->player)
		{
			for (auto j = this->enemies.begin(); j != this->enemies.end(); ++j)
			{
				auto& enemy = *j;
				if (Collision::CollisionTest(enemy, projectile))
				{
					if (!enemy->TakeDamage(projectile->getDamage()))
						j = DestroyEntity(j);
					i = DestroyEntity(i);
					break;
				}
			}
		}
		if (this->projectiles.empty())
			break;
	}
}