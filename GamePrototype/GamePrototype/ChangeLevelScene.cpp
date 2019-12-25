#include "ChangeLevelScene.h"
ChangeLevelScene::ChangeLevelScene() {
	Up = Down = false;
	Enter = true;
	curButton = 0;
	bg.setTexture(Loader::get()->TX("polytech"));
	font.loadFromFile("Assets/font.ttf");
	for (int i = 0; i < 4; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		menu[i].setCharacterSize(36);
	}
	menu[0].setString("Level 1");
	menu[1].setString("Level 2");
	menu[2].setString("Level 3");	
	menu[3].setString("Back To Menu");
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 6 + 130));
	menu[1].setPosition(sf::Vector2f(WINDOW_X / 3+50, WINDOW_Y / 4 + 130));
	menu[2].setPosition(sf::Vector2f(WINDOW_X / 3 + 50, WINDOW_Y / 3 + 130));
	menu[3].setPosition(sf::Vector2f(WINDOW_X / 3 + 50, WINDOW_Y / 2 + 130));
}
void ChangeLevelScene::Reset() {
	curButton = 0;
	Up = Down = false;
	Enter = true;
}
void ChangeLevelScene::MoveUp() {
	if (curButton > 0) {
		menu[curButton].setFillColor(sf::Color::White);
		curButton--;
		menu[curButton].setFillColor(sf::Color::Red);
	}
}
void ChangeLevelScene::MoveDown() {
		if (curButton < 3) {
			menu[curButton].setFillColor(sf::Color::White);
			curButton++;
			menu[curButton].setFillColor(sf::Color::Red);
		}
}
void ChangeLevelScene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(bg);
	for (sf::Text tx : menu) {
		target.draw(tx, states);
	}
}
int ChangeLevelScene::update(){
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
				return 1;
			case 1:
				return 2;
			case 2:
				return 3;
			case 3:
				return -2;
			}
		}
		Enter = true;
	}
	else Enter = false;
	return 0;
}
