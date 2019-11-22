#pragma once
#include "Entity.h"
#include "Gun.h"
class Enemy:public Entity
{
public:
	int Health;
	Gun gun;
	sf::Texture tx;
	Enemy(float x,float y);
	sf::Vector2f getDir();			
	void Shoot();
	void TakeDamage(int dmg);
};

