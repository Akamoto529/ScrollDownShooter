#include "Scene.h"
#include <iostream>
#include "config.h"

Scene::Scene(sf::Vector2u windowSize)
{
	size = windowSize;
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
}

bool Scene::outOfBounds(Entity* entity)
{
	if (entity->getPosition().x - entity->getRadius() > this->size.x
		|| entity->getPosition().x + entity->getRadius() < 0.f
		|| entity->getPosition().y - entity->getRadius() > this->size.y
		|| entity->getPosition().y + entity->getRadius() < 0.f)
		return true;
	return false;
}

void Scene::update()
{
	for (Projectile* projectile : this->projectiles)
	{
		projectile->step(sf::milliseconds(MSEC_PER_FRAME));
	}

	for (std::list<Projectile*>::iterator it = this->projectiles.begin(); it != this->projectiles.end(); it++)
	{
		if (outOfBounds(*it))
			it = DestroyEntity(it);
		if (this->projectiles.empty())
			break;
	}
}