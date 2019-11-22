#pragma once
#include "Projectile.h"
#include <vector>
class Gun
{
private:
	sf::Texture tx;
public:
	sf::Clock timer;	//Таймер для расчёта скорострельности
	float frate;
	float speed;
	sf::Vector2f dir;
	std::vector<Projectile> proj;
	Gun();
	void Shoot(sf::Vector2f pos);
};