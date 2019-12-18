#pragma once
#include "SFML/Graphics.hpp"
#include "Loader.h"

class Background : public sf::Drawable
{
private:
	sf::Sprite sp;
	sf::Vector2f velocity;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Background(const float speed, const int ID);
	void step(const sf::Time dt);
};