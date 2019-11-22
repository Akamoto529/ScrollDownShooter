#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Projectile:public Entity
{
public:
	sf::Vector2f dir;
	Projectile(float x, float y,sf::Texture &tx);
};

