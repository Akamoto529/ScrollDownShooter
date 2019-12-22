#pragma once
#include "SFML/Graphics.hpp"
#include "Hitbox.h"
#include "Loader.h"

// Суперкласс для физических игровых объектов
class Entity : public sf::Drawable, public sf::Transformable
{
protected:
	// Заморозка объекта для паузы и абилки.
	bool frozen;
	Hitbox hitbox;
	float speed;
	sf::Sprite sp;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Entity(const sf::Vector2f pos, const float speed, const std::string entityName);
	//~Entity();
	virtual void freeze();
	Hitbox getHitbox() const;
	sf::FloatRect getHitboxBounds() const;
	sf::FloatRect getSpriteBounds()	const;
	void move(const sf::Vector2f offset);
	void rotate(const float angle);
	void setPosition(const sf::Vector2f position);
	void setRotation(const float angle);
	virtual void step(const sf::Time dt) = 0;
	virtual void unfreeze();
};

