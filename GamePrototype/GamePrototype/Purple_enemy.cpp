#include "Purple_enemy.h"

Purple_enemy::Purple_enemy(const sf::Vector2f pos)
	: Enemy(pos, 40.f, "Purple_enemy")
{
	this->HP = 10;
	this->gun = new Purple_gun(sf::Vector2f(0, 1));
}