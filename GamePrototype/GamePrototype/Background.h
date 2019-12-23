#pragma once
#include "SFML/Graphics.hpp"
#include "Loader.h"

class Background : public sf::Drawable
{
private:
	bool frozen;
	sf::Sprite sp;
	static float speed;
	sf::Vector2f velocity;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Background(const std::string Name);
	void freeze();
	static float getSpeed();
	void step(const sf::Time dt);
	void unfreeze();
};