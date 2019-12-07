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
	AddEntities({
		new Enemy(sf::Vector2f(400, 400)),
		new Enemy(sf::Vector2f(350, 400)),
		new Enemy(sf::Vector2f(300, 400)),
		new Enemy(sf::Vector2f(450, 400)),
		new Enemy(sf::Vector2f(400, 470))
		});
	projectiles = {};
	// ...
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

	AddEntities(this->player->Shoot());
	for (Enemy* enemy : this->enemies)
		AddEntities(enemy->Shoot());
	
	for (auto i = this->projectiles.begin(); i != this->projectiles.end(); ++i)
	{
		auto& projectile = *i;
		projectile->step(dt);
		if (outOfBounds(projectile))
		{
			i = DestroyEntity(i);
			continue;
		}

		for (auto j = this->enemies.begin(); j != this->enemies.end(); ++j)
		{
			auto& enemy = *j;
			if (projectile->getOwner() == this->player && Collision::CollisionTest(enemy, projectile))
			{
				i = DestroyEntity(i);
				break;
			}
		}

		if (this->projectiles.empty() || i == this->projectiles.end())
			break;
	}
}