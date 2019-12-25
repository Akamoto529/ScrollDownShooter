#include "Green_bullet.h"

Green_bullet::Green_bullet(const sf::Vector2f pos, const sf::Vector2f direction)
	: Projectile(direction, 1, pos, 600.f, "Green_bullet")
{}