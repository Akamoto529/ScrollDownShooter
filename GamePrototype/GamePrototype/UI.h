#pragma once
#include "Player.h"
class UI : public sf::Drawable
{
	Player* player;
	sf::Texture FullHeart;
	sf::Texture EmptyHeart;
public:
	std::vector<sf::Sprite> mas;
	UI(Player *pl);
	void Update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


