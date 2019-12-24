#pragma once
#include "Player.h"
class UI : public sf::Drawable
{
	Player* player;
	std::vector<sf::Sprite> mas;
public:
	UI(Player *pl);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


