#include "Bonus.h"
#include "Player_Spread.h"
Timer Bonus::freezeTimer;

Bonus::Bonus(sf::Vector2f pos, std::string name)
	: Entity(pos, 100.f, name)
{
	this->name = name;
	this->startPos = pos;
}

Bonus* Bonus::dropBonus(const sf::Vector2f pos)
{
	int random = rand() % 1000;
	std::cout << random << std::endl;
	if (random <= 200)
		return new Bonus(pos, "hp-bonus");
	else if (random > 200 && random <= 300)
		return new Bonus(pos, "freeze-bonus");
	else if (random > 300 && random <= 400)
		return new Bonus(pos, "Spread-bonus");
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
	else if (this->name == "Spread-bonus")
	{
		player->ChangeGun(new Player_Spread(sf::Vector2f(0, -1)));
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