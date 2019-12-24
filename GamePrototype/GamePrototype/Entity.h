#pragma once
#include "SFML/Graphics.hpp"
#include "Hitbox.h"
#include "Loader.h"

// Суперкласс для физических игровых объектов
class Entity : public sf::Drawable, public sf::Transformable
{
private:
	Hitbox hitbox;
	sf::Sprite sp;
protected:
	// Заморозка объекта для паузы и абилки.
	bool frozen;
	float speed;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Entity(const sf::Vector2f pos, const float speed, const std::string entityName);
	
	void changeAsset(const sf::Vector2f pos, const std::string entityName);
	void setColor(const sf::Color color);

	virtual void freeze();
	virtual void unfreeze();

	Hitbox getHitbox() const;
	sf::FloatRect getHitboxBounds() const;
	sf::FloatRect getSpriteBounds()	const;

	void move(const sf::Vector2f offset);
	void setPosition(const sf::Vector2f position);

	void rotate(const float angle);
	void setRotation(const float angle);
	void setRotation(const sf::Vector2f direction);

	virtual void step(const sf::Time dt) = 0;
};