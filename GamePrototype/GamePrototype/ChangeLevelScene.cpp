#include "ChangeLevelScene.h"
#include "ScreenManager.h"
#include <iostream>
ChangeLevelScene::ChangeLevelScene() {
	this->selectedItemIndex = 0;
	this->bg.setTexture(Loader::get()->TX("polytech"));
	this->font.loadFromFile("Assets/font.ttf");
	this->menu[0].setFont(font);
	this->menu[0].setString("Level 1");
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setCharacterSize(36);
	this->menu[0].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 6 + 130));

	this->menu[1].setFont(font);
	this->menu[1].setFillColor(sf::Color::Red);
	this->menu[1].setString("Level 2");
	this->menu[1].setCharacterSize(36);
	this->menu[1].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 4 + 130));

	this->menu[2].setFont(font);
	this->menu[2].setFillColor(sf::Color::Red);
	this->menu[2].setString("Level 3");
	this->menu[2].setCharacterSize(36);
	this->menu[2].setPosition(sf::Vector2f(WINDOW_X / 3 + 50, WINDOW_Y / 3 + 130));

	this->menu[3].setFont(font);
	this->menu[3].setFillColor(sf::Color::Red);
	this->menu[3].setString("Back to menu");
	this->menu[3].setCharacterSize(36);
	this->menu[3].setPosition(sf::Vector2f(WINDOW_X / 3 + 50, WINDOW_Y / 2 + 130));
}
void ChangeLevelScene::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}
void ChangeLevelScene::MoveDown() {
		if (selectedItemIndex + 1 < 4) {
			menu[selectedItemIndex].setFillColor(sf::Color::Red);
			selectedItemIndex++;
			menu[selectedItemIndex].setFillColor(sf::Color::White);
		}
}
void ChangeLevelScene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(bg);
	
	target.draw(menu[0],states);
	target.draw(menu[1],states);
	target.draw(menu[2], states);
	target.draw(menu[3], states);
	}
int ChangeLevelScene::update(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		MoveDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		//возвращение инт значений нужно изменить
		if (selectedItemIndex == 0) {
			return 1;
		}
		if (selectedItemIndex == 1) {
			
			return 2;
		}
		if (selectedItemIndex == 2) {
			return 3;
		}
		if (selectedItemIndex == 3) {

			return 1;
		}
	}
	return 0;
}
