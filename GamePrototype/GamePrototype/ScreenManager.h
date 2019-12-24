#pragma once
#include"MenuScene.h"
#include"Scene.h"
class ScreenManager
{
	MenuScene* MenuScene;
	Scene* scene;
	void ChangeScene();
public:
	ScreenManager();
};

