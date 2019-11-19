#pragma once
#include <SFML/Graphics.hpp>
class Projectile
{
private:
	sf::Texture tx;
public:
	float speed;
	sf::Vector2f dir;
	sf::Sprite sprite;
	Projectile(float x, float y);
	Projectile(const Projectile &obj);
};

