#pragma once
#include "Bullet.h"
class ProjFactory
{
public:
	static Projectile* getProj(sf::Vector2f pos, sf::Vector2f dir, std::string ProjName) 
	{
		if (ProjName == "Bullet") { return new Bullet(pos, dir); }
	}
};
