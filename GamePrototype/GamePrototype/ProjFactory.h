#pragma once
#include "Bullet.h"
#include "Missile.h"
#include "Blue_bullet.h"
#include "Green_bullet.h"
#include "Purple_bullet.h"
#include "Christmas_proj.h"
#include <iostream>

class ProjFactory
{
public:
	static Projectile* getProj(sf::Vector2f pos, sf::Vector2f dir, std::string ProjName, Entity* target = nullptr)
	{
		if (ProjName == "Bullet")
			return new Bullet(pos, dir);
		else if (ProjName == "Missile")
			return new Missile(pos, dir, target);
		else if (ProjName == "Blue_bullet")
			return new Blue_bullet(pos, dir);
		else if (ProjName == "Green_bullet")
			return new Green_bullet(pos, dir);
		else if (ProjName == "Purple_bullet")
			return new Purple_bullet(pos, dir);
		else if (ProjName == "Christmas_proj")
			return new Christmas_proj(pos, dir);
		else
		{
			std::cout << "Projectile " << ProjName << " not loaded\n";
			return nullptr;
		}
	}
};