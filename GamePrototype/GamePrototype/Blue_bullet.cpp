#include "Blue_bullet.h"

Blue_bullet::Blue_bullet(const sf::Vector2f pos, const sf::Vector2f direction)
	: Projectile(direction, 1, pos, 400.f, "Blue_bullet")
{}