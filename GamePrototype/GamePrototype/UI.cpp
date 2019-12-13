#include "UI.h"
UI::UI() {
	this->EmptyHeart.loadFromFile("Assets/UI/3x/Empty.png");
	this->FullHeart.loadFromFile("Assets/UI/3x/Full.png");
	this->mas = new sf::Sprite[fullHP];
	for(int i=0;i<fullHP;i++){
		mas[i].setTexture(FullHeart);
		mas[i].setPosition(FullHeart.getSize().x*(i+1),0.f);
	}
}
