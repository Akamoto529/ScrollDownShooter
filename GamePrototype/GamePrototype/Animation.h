#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
private:
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	float switchTime;
	float totalTime;
public:
	Animation(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);
	void update(int row, float deltaTime);

	// ”брать в private.
	sf::IntRect textureRect;
};

