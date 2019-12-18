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
	this->AddEntities(player->shoot());
	for (auto j = this->enemies.begin(); j != this->enemies.end(); ++j)
	{
		auto& enemy = *j;
		if (enemy == nullptr)
			j = enemies.erase(j);
		else
		{
			enemy->step(dt);
			AddEntities(enemy->shoot());
		}

		//if (Collision::CollisionTest(enemy, this->player))
		//{
		//	enemy = nullptr;
		//	i = enemies.erase(i);
		//}

		if (this->enemies.empty() || j == this->enemies.end())
			break;
	}

	for (auto i = this->projectiles.begin(); i != this->projectiles.end(); ++i)
	{
		auto& projectile = *i;
		projectile->step(dt);

		if (outOfBounds(projectile))
			projectile = nullptr;

		if (projectile != nullptr && projectile->getHostility() != hostile)
		{
			for (auto j = this->enemies.begin(); j != this->enemies.end(); ++j)
			{
				auto& enemy = *j;
				if (Collision::CollisionTest(enemy, projectile))
				{
					if (!enemy->TakeDamage(projectile->getDamage()))
					{
						enemy = nullptr;
						j = enemies.erase(j);
					}
					projectile = nullptr;
					break;
				}
			}
		}

		if (projectile != nullptr && projectile->getHostility() != friendly && Collision::CollisionTest(this->player, projectile))
		{
			projectile = nullptr;
			i = projectiles.erase(i);
		}

		if (projectile == nullptr)
			i = projectiles.erase(i);

		if (this->projectiles.empty() || i == this->projectiles.end())
			break;
	}
}