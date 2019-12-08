#pragma once
#include "SFML/Graphics.hpp"
#include "Hitbox.h"
#include "Loader.h"

// Суперкласс для физических игровых объектов
class Entity : public sf::Drawable
{
protected:
	Hitbox hitbox;
	float speed;
	sf::Sprite sp;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Entity(const sf::Vector2f pos, const float speed, const int entityID);
	//~Entity();
	sf::FloatRect getGlobalBounds()	const;
	Hitbox getHitbox() const;
	sf::Vector2f getPosition() const;
	void move(const sf::Vector2f offset);
	void setPosition(const sf::Vector2f position);
	void setTexture(const int ID, const sf::Vector2f currentPos);
	virtual void step(const sf::Time dt) = 0;
};
