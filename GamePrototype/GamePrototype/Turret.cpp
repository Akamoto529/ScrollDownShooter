#include "Turret.h"

Turret::Turret(const sf::Vector2f pos, Entity* target)
	: Enemy(pos, Background::getSpeed(), "Turret")
{
	this->HP = 3;
	this->gun = new Launcher(sf::Vector2f(0, 1), target);
	this->target = target;
}

void Turret::step(const sf::Time dt)
{
	if (!frozen) {
		this->move(sf::Vector2f(0, this->speed*dt.asSeconds()));
		sf::Vector2f newDir = target->getPosition() - this->getPosition();
		this->gun->setDirection(newDir);
		this->setRotation(newDir);
	}
}