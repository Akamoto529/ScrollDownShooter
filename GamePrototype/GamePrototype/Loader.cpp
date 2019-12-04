#include "Loader.h"
Loader* Loader::instance = 0;

Loader::Loader()
{
	player.loadFromFile("Assets/Player.png");
	enemy.loadFromFile("Assets/Enemy.png");
	projectile.loadFromFile("Assets/Projectile.png");
}

sf::Texture& Loader::GetPlayer()
{
	return player;
}

sf::Texture& Loader::GetProjectile()
{
	return projectile;
}