#include "Bonus.h"

Bonus::Bonus(sf::Vector2f pos, std::string name)
	: Entity(pos, 100.f, name)
{
	this->startPos = pos;
}

static void increaseHP(Player* player);

void Bonus::step(const sf::Time dt)
{
	this->move(sf::Vector2f(cos((this->getPosition().y-this->startPos.y)/20)/5, (float)dt.asMicroseconds()*speed/1000000));
}