#pragma once
#include "Entity.h"
#include "Gun.h"
class Enemy:public Entity
{
public:
	int Health;
	Gun gun;
	std::vector<sf::Vector2f> path;
	int curPoint;
	Enemy(float x,float y,sf::Texture &tx);
	sf::Vector2f getDir();			
	void Shoot();
	void TakeDamage(int dmg);
};

