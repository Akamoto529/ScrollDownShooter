#include "Grey_enemy.h"

Grey_enemy::Grey_enemy(const sf::Vector2f pos)
	: Enemy(pos, 40.f, "Grey_enemy")
{
	this->HP = 3;
	this->gun = new Blue_gun(sf::Vector2f(0, 1));
};