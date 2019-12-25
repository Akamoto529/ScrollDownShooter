#include "Green_enemy.h"

Green_enemy::Green_enemy(const sf::Vector2f pos)
	: Enemy(pos, 40.f, "Green_enemy")
{
	this->HP = 5;
	this->gun = new Green_gun(sf::Vector2f(0, 1));
};