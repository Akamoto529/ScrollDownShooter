#include "MenuScene.h"
#include "ScreenManager.h"
#include <iostream>
MenuScene::MenuScene() {
	this->selectedItemIndex = 0;
	this->bg.setTexture(Loader::get()->TX("polytech"));
	this->font.loadFromFile("Assets/font.ttf");
	this->menu[0].setFont(font);
	this->menu[0].setString("Play");
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setCharacterSize(36);
	this->menu[0].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 6 + 130));

	this->menu[1].setFont(font);
	this->menu[1].setFillColor(sf::Color::Red);
	this->menu[1].setString("End");
	this->menu[0].setCharacterSize(36);
	this->menu[1].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 4 + 130));
}
void MenuScene::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}
void MenuScene::MoveDown() {
		if (selectedItemIndex + 1 < 2) {
			menu[selectedItemIndex].setFillColor(sf::Color::Red);
			selectedItemIndex++;
			menu[selectedItemIndex].setFillColor(sf::Color::White);
		}
}
void MenuScene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(bg);
	target.draw(menu[1],states);
	target.draw(menu[0],states);
	}
int MenuScene::update(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		MoveDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (selectedItemIndex == 0) {
			return 1;
		}
		if (selectedItemIndex == 1) {
			
			return -1;
		}
	}
	return 0;
}