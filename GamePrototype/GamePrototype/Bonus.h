#pragma once
#include "Entity.h"
#include "Player.h"

class Bonus : public Entity
{
private:
	std::string name;
	sf::Vector2f startPos;
public:
	Bonus(sf::Vector2f pos, std::string name);
	void makeAction(Player* player) const;
	virtual void step(const sf::Time dt) override;
};