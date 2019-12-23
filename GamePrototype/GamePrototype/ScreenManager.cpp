#include "ScreenManager.h"

ScreenManager::ScreenManager() {}

void ScreenManager::update(sf::Time leftTillRender)
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

	GameScene.update(leftTillRender);
}
void ScreenManager::Render(sf::RenderWindow* window) {

	window->draw(GameScene);
}