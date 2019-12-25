#pragma once
#include "Entity.h"
#include "Scene.h"
#include "Player.h"

class Scene;
class Bonus : public Entity
{
private:
	std::string name;
	sf::Vector2f startPos;

	static Timer freezeTimer;
	static Timer damageTimer;
public:
	Bonus(sf::Vector2f pos, std::string name);

	void pause();
	void unpause();

	static Bonus* dropBonus(const sf::Vector2f pos);
	void makeAction(Scene* scene, Player* player) const;

	virtual void step(const sf::Time dt) override;
	static void update(Scene* scene, Player* player);
};