#include "UI.h"
UI::UI(Player* pl) {
	this->EmptyHeart.loadFromFile("Assets/UI/3x/Empty.png");
	this->FullHeart.loadFromFile("Assets/UI/3x/Full.png");
	this->player = pl;
	this->mas = new sf::Sprite[player->getFullHP()];
	for(int i=0;i< player->getFullHP();i++){
		mas[i].setPosition(FullHeart.getSize().x*(i+1),0.f);
	}
}
void UI::Update() {
	for (int i = 0; i < player->getHP();i++) {
		mas[i].setTexture(FullHeart);
	}
	for (int i = player->getHP(); i < player->getFullHP(); i++) {
		mas[i].setTexture(EmptyHeart);
	}
}
