#pragma once
#include "Entity.h"
#include "Player.h"
class UI :public Entity
{
public:
	sf::Texture tx;
	UI(float x, float y,int health);
	void drawHP(int health);
};


