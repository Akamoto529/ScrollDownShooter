#include "Bonus.h"

Bonus::Bonus(sf::Vector2f pos, std::string name)
	: Entity(pos, 100.f, name)
{
	this->name = name;
	this->startPos = pos;
}

void Bonus::makeAction(Player* player) const
{
	if (this->name == "hp-bonus")
		player->setHP(player->getFullHP());
}

void Bonus::step(const sf::Time dt)
{
	if (!frozen)
		this->move(sf::Vector2f(cos((this->getPosition().y-this->startPos.y)/20)/5, dt.asSeconds()*speed));
}