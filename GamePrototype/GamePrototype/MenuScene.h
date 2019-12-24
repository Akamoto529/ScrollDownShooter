#pragma once
#include "loader.h"
#include "config.h"
#include "Scene.h"

class MenuScene : public sf::Drawable
{
private:
	int curButton;
	bool Up, Down, Enter;
	sf::Sprite bg;
	sf::Font font;
	sf::Text menu[2];
	void MoveUp();
	void MoveDown();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	MenuScene();
	int update();
	void Reset();
};

