#pragma once
#include "Player.h"
class UI
{
public:
	sf::Texture FullHeart;
	sf::Texture EmptyHeart;
	sf::Sprite *mas;
	int fullHP = 5;
	int curHp = 5;
	UI();
};


