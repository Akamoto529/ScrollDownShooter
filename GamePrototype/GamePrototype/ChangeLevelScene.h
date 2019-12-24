#pragma once
#include "loader.h"
#include "config.h"
#include "Scene.h"

class ChangeLevelScene : public sf::Drawable
{
private:
	int curButton;
	bool Up, Down, Enter;
	sf::Sprite bg;
	sf::Font font;
	sf::Text menu[4];
	void MoveUp();
	void MoveDown();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:	
	ChangeLevelScene();
	int update();	
	void Reset();
};


