#pragma once
#include "Enemy.h"
#include "Green_gun.h"
#include "Purple_gun.h"
class Invader : public Enemy
{
private:
	Purple_gun* SidegunLeft;
	Purple_gun* SidegunRight;
	Green_gun* Shotgun;
	sf::Vector2f startPos;
public:
	Invader(sf::Vector2f pos);
	void step(sf::Time dt);
	virtual bool takeDamage(const int dmg) override;
	virtual std::list<Projectile*> shoot() const override;
};

