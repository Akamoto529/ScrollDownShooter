#pragma once
#include "Scene.h"
#include "Timer.h"
#include "SFML/Graphics.hpp"
#include "config.h"
class ScreenManager
{
	Scene GameScene;
public:
	ScreenManager();
	void update(sf::Time leftTillRender);
	void Render(sf::RenderWindow* window);
};

