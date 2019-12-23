#pragma once
#include "Bullet.h"
#include "Missile.h"

class ProjFactory
{
public:
	static Projectile* getProj(sf::Vector2f pos, sf::Vector2f dir, int hostility, std::string ProjName, Entity* target = nullptr)
	{
		if (ProjName == "Bullet")
			return new Bullet(pos, dir, hostility);
		else if (ProjName == "Missile")
			return new Missile(pos, dir, hostility, target);
		else
			return nullptr;
	}
};
