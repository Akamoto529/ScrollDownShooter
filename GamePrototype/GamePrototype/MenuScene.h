#pragma once
#include "loader.h"
#include "config.h"
#include "Scene.h"

class MenuScene : public sf::Drawable
{
private:
	sf::Sprite bg;
	sf::Sprite pl;
	sf::Font font;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
public:	int update();
	sf::Text menu[2];
	void MoveUp();
	void MoveDown();
public:
	MenuScene();
	int selectedItemIndex;
};

