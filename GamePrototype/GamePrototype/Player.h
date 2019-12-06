#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "Entity.h"
#include<vector>
class Player:public Entity
{
private:
public:
	Gun gun;
	int Health;	
	sf::Texture tx;
	Player();
	sf::Vector2f getDir();			//Функция, возвращающая направление движения
	void Shoot();
	int GetHP();
};

