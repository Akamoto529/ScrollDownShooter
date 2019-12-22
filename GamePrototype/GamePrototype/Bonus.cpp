#include "Bonus.h"

Bonus::Bonus(sf::Vector2f pos, std::string name)
	: Entity(pos, 100.f, name)
{
	this->startPos = pos;
}

//void Bonus::increaseHP(Player* player)
//{
//	player.
//}

void Bonus::step(const sf::Time dt)
{
	if (!frozen)
		this->move(sf::Vector2f(cos((this->getPosition().y-this->startPos.y)/20)/5, dt.asSeconds()*speed));
}