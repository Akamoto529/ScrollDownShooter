#pragma once
#include "loader.h"
#include "config.h"
#include "Scene.h"

class ChangeLevelScene : public sf::Drawable
{
private:
	sf::Sprite bg;
	sf::Font font;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:	int update();
	  sf::Text menu[4];
	  void MoveUp();
	  void MoveDown();
public:
	ChangeLevelScene();
	int selectedItemIndex;
};


