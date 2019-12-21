#pragma once
#include "Entity.h"
#include "Player.h"

class Bonus : public Entity
{
private:
	sf::Vector2f startPos;
public:
	Bonus(sf::Vector2f pos, std::string name);
	static void increaseHP(Player* player);
	virtual void step(const sf::Time dt) override;
};