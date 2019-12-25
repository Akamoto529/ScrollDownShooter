#include "Purple_bullet.h"

Purple_bullet::Purple_bullet(const sf::Vector2f pos, const sf::Vector2f direction)
	: Projectile(direction, 1, pos, 300.f, "Purple_bullet")
{}