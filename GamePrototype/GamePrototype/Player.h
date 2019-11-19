#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include<vector>
class Player
{
private:
public:
	sf::Clock timer;
	std::vector<Projectile> proj;
	int Health;
	float Speed;
	float frate;
	sf::Sprite sprite;
	sf::Vector2f Dir;
	sf::Texture tx;
	Player();
	sf::Vector2f getDir();
	void Shoot();
};

