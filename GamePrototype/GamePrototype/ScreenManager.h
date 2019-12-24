#pragma once
#include "Scene.h"
#include "MenuScene.h"
#include "ChangeLevelScene.h"
#include "Timer.h"
#include "SFML/Graphics.hpp"
#include "config.h"
class ScreenManager
{
	sf::RenderWindow* window;
	int curScene;
	ChangeLevelScene LvlSelectScene;
	MenuScene MainMenu;
	Scene GameScene;
public:
	ScreenManager();
	void update(sf::Time leftTillRender);
	void Render();
	void switchScene(int SceneNum);
};

