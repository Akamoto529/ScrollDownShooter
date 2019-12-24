#pragma once
#include "Bullet.h"
#include "Missile.h"

class ProjFactory
{
public:
	static Projectile* getProj(sf::Vector2f pos, sf::Vector2f dir, std::string ProjName, Entity* target = nullptr)
	{
		if (ProjName == "Bullet")
			return new Bullet(pos, dir);
		else if (ProjName == "Missile")
			return new Missile(pos, dir, target);
		else
			return nullptr;
	}
};
