#include "Blue_enemy.h"
#include "Blue_gun.h"

Blue_enemy::Blue_enemy(const sf::Vector2f pos)
	: Enemy(pos, 60.f, "Blue_enemy")
{
	this->HP = 3;
	this->gun = new Blue_gun(sf::Vector2f(0, 1));
};