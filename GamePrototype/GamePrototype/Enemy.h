#pragma once
#include "Entity.h"
#include "Gun.h"
class Enemy:public Entity
{
public:
	int Health;
	Gun gun;
	int curPoint;
	Enemy(float x,float y,sf::Texture &tx);
	std::vector<sf::Vector2f> Path;
	void Shoot();
	void TakeDamage(int dmg);
	void move(float frametime);
};

