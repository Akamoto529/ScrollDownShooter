#include "Scene.h"
#include <iostream>
#include "config.h"
#include "Collision.h"

Scene::Scene()
{
	this->windowSize.x = (uint16_t)WINDOW_X;
	this->windowSize.y = (uint16_t)WINDOW_Y;
	this->bonuses = {};
	this->enemies = {};
	this->projectiles = {};

	bg = new Background(200, "space");
	this->lvl.Load(1);
	this->player = new Player();
	AddEntities(lvl.getEnemies());
}

void Scene::AddEntities(std::list<Bonus*> bonuses)
{
	for (Bonus* bonus : bonuses)
	{
		this->bonuses.push_back(bonus);
	}
}

void Scene::AddEntities(std::list<Enemy*> enemies)
{
	for (Enemy* enemy : enemies)
	{
		this->enemies.push_back(enemy);
		this->enemies.back()->setRotation(180);
	}
}

void Scene::AddEntities(std::list<Projectile*> projectiles)
{
	for (Projectile* projectile : projectiles)
	this->projectiles.push_back(projectile);
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*bg, states);
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

	for (Bonus* bonus : this->bonuses)
	{
		target.draw(*bonus, states);
	}
}

void Scene::freeze()
{
	bg->freeze();
	for (auto& enemy : enemies)
		enemy->freeze();
	for (auto& projectile : projectiles)
		if (projectile->getHostility() != friendly)
			projectile->freeze();
}

bool Scene::outOfBounds(const Entity* entity) const
{
	sf::FloatRect box = entity->getSpriteBounds();
	if (box.top+box.height < 0
		|| box.left+box.width < 0
		|| box.top > this->windowSize.y
		|| box.left > this->windowSize.x)
		return 1;
	return 0;
}

void Scene::unfreeze()
{
	bg->unfreeze();
	for (auto& enemy : enemies)
		enemy->unfreeze();
	for (auto& projectile : projectiles)
		projectile->unfreeze();
}

void Scene::update(const sf::Time dt)
{
	bg->step(dt);
	player->step(dt);
	this->AddEntities(player->shoot());

	for (auto k = this->bonuses.begin(); k != this->bonuses.end(); ++k)
	{
		auto& bonus = *k;
		bonus->step(dt);
		if (Collision::CollisionTest(bonus, this->player))
		{
			bonus = nullptr;
			k = this->bonuses.erase(k);
		}

		if (this->bonuses.empty() || k == this->bonuses.end())
			break;
	}

	for (auto i = this->projectiles.begin(); i != this->projectiles.end(); ++i)
	{
		auto& projectile = *i;
		projectile->step(dt);

		if (outOfBounds(projectile))
			projectile = nullptr;

		else if (projectile->getHostility() != hostile)
		{
			for (auto& enemy : this->enemies)
			{
				if (Collision::CollisionTest(enemy, projectile))
				{
					if (!enemy->takeDamage(projectile->getDamage()))
					{
						this->AddEntities({new Bonus(enemy->getPosition(),"hp-bonus")});
						enemy = nullptr;
					}
					projectile = nullptr;
					break;
				}
			}
		}

		if (projectile != nullptr && projectile->getHostility() != friendly && Collision::CollisionTest(this->player, projectile))
		{
			if (!player->takeDamage(projectile->getDamage()))
				std::cout << "u ded\n";
			projectile = nullptr;
		}

		if (projectile == nullptr)
			i = projectiles.erase(i);

		if (this->projectiles.empty() || i == this->projectiles.end())
			break;
	}

	for (auto j = this->enemies.begin(); j != this->enemies.end(); ++j)
	{
		auto& enemy = *j;
		if (Collision::CollisionTest(enemy, this->player))
		{
			this->AddEntities({ new Bonus(enemy->getPosition(),"hp-bonus") });
			enemy = nullptr;
			this->player->takeDamage(player->getFullHP());
			std::cout << player->getHP();
		}

		if (enemy == nullptr)
			j = enemies.erase(j);
		else
		{
			enemy->step(dt);
			AddEntities(enemy->shoot());
		}

		if (this->enemies.empty() || j == this->enemies.end())
			break;
	}
}