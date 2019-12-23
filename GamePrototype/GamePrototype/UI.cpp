#include "UI.h"
#include <iostream>
UI::UI(Player* pl) {
	this->EmptyHeart.loadFromFile("Assets/UI/3x/Empty.png");
	this->FullHeart.loadFromFile("Assets/UI/3x/Full.png");
	this->player = pl;
	this->mas.resize(player->getFullHP());
	for(int i=0;i< player->getFullHP();i++){
		mas[i].setPosition((float)FullHeart.getSize().x*i,0.f);
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
void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < mas.size(); i++) {
		target.draw(mas[i], states);
	}
}