#include "Bonus.h"

Timer Bonus::freezeTimer;

Bonus::Bonus(sf::Vector2f pos, std::string name)
	: Entity(pos, 100.f, name)
{
	this->name = name;
	this->startPos = pos;
}

Bonus* Bonus::dropBonus(const sf::Vector2f pos)
{
	int random = std::rand() % 100;
	if (random <= 20)
		return new Bonus(pos, "hp-bonus");
	else if (random > 20 && random <= 40)
		return new Bonus(pos, "freeze-bonus");
	else
		return {};
}

void Bonus::pause()
{
	this->Entity::freeze();
	freezeTimer.pause();
}

void Bonus::unpause()
{
	this->Entity::unfreeze();
	freezeTimer.start();
}

void Bonus::makeAction(Scene* scene, Player* player) const
{
	if (this->name == "hp-bonus")
	{
		player->heal();
		player->setColor(sf::Color(0, 255, 0));
	}
	else if (this->name == "freeze-bonus")
	{
		freezeTimer.reset();
		scene->freeze();
	}
}

void Bonus::step(const sf::Time dt)
{
	if (!frozen)
		this->move(sf::Vector2f(cos((this->getPosition().y-this->startPos.y)/20)/5, dt.asSeconds()*speed));
}

void Bonus::update(Scene* scene, Player* player)
{
	if (!freezeTimer.isPaused() && freezeTimer.getElapsedTime() >= sf::seconds(5))
	{
		scene->unfreeze();
		freezeTimer.reset();
		freezeTimer.pause();
	}
}