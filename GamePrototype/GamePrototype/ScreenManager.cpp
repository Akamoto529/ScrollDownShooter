#include "ScreenManager.h"

ScreenManager::ScreenManager() {}

void ScreenManager::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		GameScene.freeze();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		GameScene.unfreeze();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		GameScene.LoadLevel(1);
	}
	else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		GameScene.LoadLevel(2);
	}

	GameScene.update();
}
void ScreenManager::Render(sf::RenderWindow* window) {

	window->draw(GameScene);
}