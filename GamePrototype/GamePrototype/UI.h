#pragma once
#include "Player.h"
class UI
{
	Player* player;
	sf::Texture FullHeart;
	sf::Texture EmptyHeart;
public:
	sf::Sprite *mas;
	UI(Player *pl);
	void Update();
};


