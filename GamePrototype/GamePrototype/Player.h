#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "Entity.h"
#include<vector>
class Player:public Entity
{
private:
public:
	const int constHP = 5;
	Gun gun;
	int Health;	
	sf::Texture tx;
	Player();
	sf::Vector2f getDir();			//Функция, возвращающая направление движения
	void Shoot();
};

