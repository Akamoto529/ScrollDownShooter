#include "UI.h"
#include "Loader.h"
#include <iostream>

UI::UI(Player* pl)
{
	this->player = pl;
	this->mas.resize(player->getFullHP());
	for(int i=0;i< player->getFullHP();i++)
	{
		mas[i].setTexture(Loader::get()->TX("Full-heart"));
		mas[i].setPosition((float)mas[i].getTexture()->getSize().x*i,0.f);
	}
}
void UI::update() {
	for (int i = 0; i < player->getHP();i++) {
		mas[i].setTexture(Loader::get()->TX("Full-heart"));
	}
	for (int i = player->getHP(); i < player->getFullHP(); i++) {
		mas[i].setTexture(Loader::get()->TX("Empty-heart"));
	}
}
void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < mas.size(); i++) {
		target.draw(mas[i], states);
	}
}