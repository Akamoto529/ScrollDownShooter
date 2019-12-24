#include "ScreenManager.h"

ScreenManager::ScreenManager() {
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_X, WINDOW_Y), "test v2");
	this->curScene = 1;
}

void ScreenManager::update(sf::Time leftTillRender)
{
	/*Список индексов:
	-3 - выход из игры
	-2 - переход в главное меню
	-1 - переход на выбор уровней
	0 - ничего не делать, остаться в текущей сцене
	1,2... - Переход на i-й уровень
	=======
	Сцены
	1 - Главное меню
	2 - выбор уровня
	3 - игра
	*/
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
	int Index;
	switch (curScene)
	{
	case 1:
		Index = MainMenu.update();
		break;
	case 2:
		Index = LvlSelectScene.update();
		break;
	case 3:
		Index = GameScene.update(leftTillRender);
		break;
	default:
		break;
	}
	if (Index < 0) {
		switch (Index) {
		case -3:
			window->close();
			break;
		case -2:
			MainMenu.Reset();
			switchScene(1);
			break;
		case -1:
			LvlSelectScene.Reset();
			switchScene(2);
			break;
		}
	}
	if (Index > 0) {
		GameScene.LoadLevel(Index);
		switchScene(3);
	}
}
void ScreenManager::Render() {
	window->clear();
	switch (curScene)
	{
	case 1:
		window->draw(MainMenu);
		break;
	case 2:
		window->draw(LvlSelectScene);
		break;
	case 3:
		window->draw(GameScene);
		break;
	default:
		break;
	}
	window->display();
}
void ScreenManager::switchScene(int SceneNum) {
	this->curScene = SceneNum;
}