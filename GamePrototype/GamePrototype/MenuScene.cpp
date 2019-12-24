#include "MenuScene.h"
MenuScene::MenuScene() {
	Up = Down = false;
	Enter = true;
	this->curButton = 0;
	this->bg.setTexture(Loader::get()->TX("polytech"));
	this->font.loadFromFile("Assets/font.ttf");
	for (int i = 0; i < 2; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::Red);
		menu[i].setCharacterSize(36);
	}
	this->menu[0].setString("Play");
	this->menu[0].setFillColor(sf::Color::White);
	this->menu[0].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 6 + 130));
	this->menu[1].setString("End");
	this->menu[1].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 4 + 130));
}
void MenuScene::Reset() {
	curButton = 0;
	Up = Down = false;
	Enter = true;
}
void MenuScene::MoveUp() {
	if (curButton > 0) {
		menu[curButton].setFillColor(sf::Color::Red);
		curButton--;
		menu[curButton].setFillColor(sf::Color::White);
	}
}
void MenuScene::MoveDown() {
		if (curButton < 1) {
			menu[curButton].setFillColor(sf::Color::Red);
			curButton++;
			menu[curButton].setFillColor(sf::Color::White);
		}
}
void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(bg);
	for (sf::Text tx : menu) {
		target.draw(tx, states);
	}
}
int MenuScene::update(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		if (!Up) MoveUp();
		Up = true;
	}
	else Up = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		if (!Down) MoveDown();
		Down = true;
	}
	else Down = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
		if (!Enter) {
			switch (curButton)
			{
			case  0:
				return -1;
			case 1:
				return -3;
			}
		}
		Enter = true;
	}
	else Enter = false;
	return 0;
}